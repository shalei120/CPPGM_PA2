#include<iostream>
#include<string>
using namespace std;
int HexCharToValue(int c)
{
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': return 10;
	case 'a': return 10;
	case 'B': return 11;
	case 'b': return 11;
	case 'C': return 12;
	case 'c': return 12;
	case 'D': return 13;
	case 'd': return 13;
	case 'E': return 14;
	case 'e': return 14;
	case 'F': return 15;
	case 'f': return 15;
	}
}
char ValueToHexChar(int c)
{
	switch (c)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	}
}
int main(){
	string ppnumber = "00017777777777";
	string num16 = "0";
	int w = 10,start = 0;
	if(ppnumber[0] == '0'){
		if(ppnumber[1] == 'x' || ppnumber[1] == 'X'){start = 2; w = 16;}
		else {start = 1; w = 8;}
	}
	if(w == 16) num16 = ppnumber.substr(2);
	else{
		for(int i = start;i < ppnumber.length();i++){
			int c = 0;
			for(int j = 0;j < num16.length();j++){		// mutiply w
				int curr = HexCharToValue(num16[j]) ;
				num16[j] = ValueToHexChar((curr * w + c) % 16);	
				c = (curr * w + c) / 16;
			}
			if(c > 0) num16 += ValueToHexChar(c);
			cout<<"get "<<ppnumber[i]<<"   *8  num16 "<<num16<<endl;
			c = ppnumber[i] - '0'; 
			for(int j = 0;j < num16.length();j++){		// add current number 
				int curr = HexCharToValue(num16[j]) ;
				num16[j] = ValueToHexChar((curr + c) % 16);	
				c = (curr + c) / 16;
			}
			if(c > 0) num16 += ValueToHexChar(c);
			cout<<"get "<<ppnumber[i]<<"   +"<<ppnumber[i]<<"  num16 "<<num16<<endl;
		}
	}
	cout<<"num16"<<num16<<endl;
}
