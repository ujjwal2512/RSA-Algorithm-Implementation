#include<iostream>
#include<math.h>
using namespace std;

//function to check for prime number
int prime(long int l)
{
    for (int i=2;i<=sqrt(l);i++)
    {
        if (l%i==0){
        return 0;}
    }
return 1;
}

//function to calculate gcd
int gcd(int a,int b){ 
   int t;
   while(1){
      t= a%b;
      if(t==0)
      return b;
      a=b;
      b=t;
   }
}

int main(){
    double p,q,n,u,e,j,o,d,c,m;
    long int prime_check;
    long int count=0;
    cout<<"1st prime no."<<"\n";
    cin>>p;
    
//checking p for prime number
    prime_check= prime(p);
    while(prime_check==0)
    {
        cout << "Wrong Input. Please choose a valid prime number \n";
        cout<<" 1st prime no."<<"\n";
        cin>>p;
        prime_check= prime(p);
    }
    
//checking q for prime number
    cout<<"2nd prime no."<<"\n";
    cin>>q;
    prime_check= prime(q);
    while(prime_check==0)
    {
        cout << "Wrong Input. Please choose a valid prime number \n";
        cout<<" 2nd prime no."<<"\n";
        cin>>q;
        prime_check= prime(q);
    }
    
//calculation of other RSA elements
//e and n are public keys
    n=p*q;   
    j=(p-1)*(q-1);
    e=2;
    while(e<j){
      u=gcd(e,j);
      if(u==1)
         break;
      else
         e++;
    }
    o=1/e;
    d=fmod(o,j);
    double msg;
    cout<<"Enter integer to be encrypted"<<"\n"; 
    cin>>msg;
    
//encryption part
    c=pow(msg,e); 
    m=pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
    cout<<"Encrypted integer = "<<c<<"\n";
    
//decryption part
    double x,y;
    cout<<"Enter the private keys p and q"<<"\n";
    cin>>x>>y;
    
//if the private keys matches then only decryption is performed
//if the attempt is wrong for 3 times then the program quits 
    while((x!=p)&&(y!=q)){
        count++;
        if(count>2){
            cout<<"Access Denied. Try with correct values"<<"\n";
            exit(1);
        }else{
            cout<<"Try again. Enter valid private keys p and q"<<"\n";
            cin>>x>>y;
        }
    }
    if((x==p)&&(y==q)){
        cout<<"Decrypted integer = "<<m<<"\n";
    }
return 0;
}