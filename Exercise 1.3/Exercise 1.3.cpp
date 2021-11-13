// Exercise 1.3 – Joining strings
//

#include "stdafx.h"
#include <iostream> 
using namespace std;

char* join(const char*, const char*);
char* joinb(const char*, const char*);

int _tmain(int argc, _TCHAR* argv[])
{

	cout << join("alpha", "bet") << endl;
	cout << joinb("duck", "soup") << endl;

//	za tem bi bilo treba naredit delete na novo rezerviranih stringov v join in joinb, sicer dobiš
//	prazne prostore v pomnilniku, leakage - glej naslednjo nalogo. 
//	Glavna main procedura bi morala zgledat takole:

//	char *p=join("alpha", "bet");
//	char *q=joinb("duck", "soup");
//	cout << p << endl;
//	cout << q << endl;
//	delete q;						// briši stringe, ki so bili narejeni v join in joinb. V obratnem vrstnem redu
//	delete p;						// kot so nastajali... last in first out !!!

	return 0;
}

char* join(const char* a, const char* b) {
	char *retval = new char[strlen(a) + strlen(b) + 1] {0}; // rezervira nov array skupne dolžine plus končna nula in ga napolni z nulami
	strcat(retval, a);										// prištuka prvi string na praznega
	strcat(retval, b);										// prištuka drugi string na konec prvega
	return retval;											// vrne pointer na kompletna čreva
}

char* joinb(const char* a, const char* b) {					
	char *retval = new char[strlen(a) + strlen(b) + 2] {0}; // rezervira nov array skupne dolžine plus space PLUS končna nula in ga napolni z nulami
	strcat(retval, a);										// prištuka prvi string na praznega										
	strcat(retval, " ");									// prištuka space na konec prvega
	strcat(retval, b);										// prištuka drugi string na konec space
	return retval;											// vrne pointer na kompletna čreva
}
