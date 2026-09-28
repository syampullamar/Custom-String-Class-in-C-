#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class strin 
{
char *s;
public:
strin()
{
//cout<<"default constructor"<<endl;//<<"enter a string"<<endl;
s=new char[40];
//cin>>s;
}
strin(const char *p)
{
//cout<<"parametrised constructor"<<endl;
s=new char(strlen(p)+1);
strcpy(s,p);
}
strin(const strin &t)
{
//cout<<"copy constructor"<<endl;
s=new char[strlen(t.s)+1];
strcpy(s,t.s);
}
~strin()
{
//cout<<"destructor"<<endl;
}
strin operator+(strin t);
strin operator=(strin t);
char& operator[](int t);
bool operator>(strin t);
bool operator<(strin t);
bool operator>=(strin t);
bool operator<=(strin t);
bool operator!=(strin t);
bool operator==(strin t);
friend istream& operator>>(istream &,strin &);
friend ostream& operator<<(ostream &,strin &);
friend strin& strcpy(strin& s1,strin& s2);
friend strin& strncpy(strin& s1,strin& s2,int t);
friend int strcmp(strin& s1,strin& s2);
friend int strncmp(strin& s1,strin& s2,int t);
friend strin& strcat(strin& ,strin& );
friend strin& strncat(strin& ,strin& ,int t);
friend strin& strrev(strin& );
friend strin& strupper(strin& s1);
friend strin& strlower(strin& s1);
friend char* strchr(strin& s1,char t);
friend char* strrchr(strin& s1,char t);
friend char* strstr(strin& s1,strin s2);
friend int strlen(strin s1);
};

int strlen(strin s1)
{
int i=0;
for( ;s1[i]!='\0';i++);
return i;
}

char* strstr(strin& s1,strin s2)
{
int i=0,j=0,k=0;
while(s1[i]!='\0')
{
for(k=i,j=0;s2[j]!='\0';j++,k++)
if(s1[k]!=s2[j])
break;
if((j-1)==strlen(s2))
return &s1[i];
i++;
}
return NULL;
}

char* strrchr(strin& s1,char t)
{
int i=0;
while(s1[i+1]!='\0')
i++;
for( ;i>=0;i--)
if(s1[i]==t)
return &s1[i];
return 0;
}

char* strchr(strin& s1,char t)
{
int i=0;
while(s1[i]!='\0')
{
if(s1[i]==t)
return &s1[i];
i++;
}
return 0;
}

strin& strlower(strin& s1)
{
for(int i=0;s1[i]!='\0';i++)
if(s1[i]>='A'&&s1[i]<='Z')
s1[i]=s1[i]+32;
return s1;
}

strin& strupper(strin& s1)
{
for(int i=0;s1[i]!='\0';i++)
if(s1[i]>='a'&&s1[i]<='z')
s1[i]=s1[i]-32;
return s1;
}

strin& strrev(strin& s1)
{
int i=0,j=0;
char t;
while(s1[i+1]!='\0')
i++;
while(j<i)
{
t=s1[i];
s1[i]=s1[j];
s1[j]=t;
i--,j++;
}
return s1;
}

strin& strncat(strin &x1,strin& x2,int t)
{
int i=0;
while(x1[i]!='\0')
i++;
for(int j=0;j<t;j++)
x1[i++]=x2[j];
x1[i]='\0';
return x1;
}

strin& strcat(strin& x1,strin& x2)
{
int i=0;
while(x1[i]!='\0')
i++;
for(int j=0;x2[j]!='\0';j++)
x1[i++]=x2[j];
x1[i]='\0';
return x1;
}

int strncmp(strin& s1,strin& s2,int t)
{
int i;
for(i=0;i<t-1;i++)
if(s1[i]!=s2[i])
break;
return (s1[i]-s2[i]);
}

int strcmp(strin& s1,strin& s2)
{
int i;
for(i=0;(s1[i]!='\0')&&(s2[i]!='\0');i++)
if(s1[i]!=s2[i])
break;
return (s1[i]-s2[i]);
}

strin& strncpy(strin& x1,strin& x2,int t)
{
int i;
for(i=0;i<t;i++)
x1[i]=x2[i];
x1[i]='\0';
return x1;
}

strin& strcpy(strin& x1,strin& x2)
{
int i=0;
while(x2[i]!='\0')
{
x1[i]=x2[i];
i++;
}
x1[i]='\0';
return x1;
}

strin strin::operator+(strin t)
{
strin res;
res.s=strcat(s,t.s);
return res;
}
strin strin::operator=(strin t)
{
s=t.s;
return t;
}

char& strin::operator[](int t)
{
return s[t];
}
bool strin::operator>(strin t)
{
if(strcmp(s,t.s)>0)
return true;
else
return false;
}
bool strin::operator<(strin t)
{
if(strcmp(s,t.s)<0)
return true;
else
return false;
}
bool strin::operator<=(strin t)
{
if((strcmp(s,t.s)<0)||(strcmp(s,t.s)==0))
return true;
else
return false;
}
bool strin::operator>=(strin t)
{
if((strcmp(s,t.s)>0)||(strcmp(s,t.s)==0))
return true;
else
return false;
}
bool strin::operator!=(strin t)
{
if(strcmp(s,t.s)!=0)
return true;
else
return false;
}
bool strin::operator==(strin t)
{
if(strcmp(s,t.s)==0)
return true;
else
return false;
}
istream& operator>>(istream &in,strin &t)
{
ofstream fout("data");
char ch;
int c=0,i=0;
while(1)
{
in.get(ch);
if(ch=='\n')
break;
fout<<ch;
}
fout.close();
ifstream fin("data",ios::in);
fin.clear();
fin.seekg(0,ios::beg);
while(fin.get()!=-1)
{
c++;
}
t.s=new char[c+1];
fin.clear();
fin.seekg(0,ios::beg);
i=0;
while((ch=fin.get())!=-1)
t.s[i++]=ch;
fin.close();
return in;
}

ostream& operator<<(ostream &out,strin &t)
{
out<<t.s;
return out;
}


int main()
{
strin temp1,s1("ndckcnkabhorioh"),s2("abcd"),s3("ijkl"),s4("ab"),s,temp;
cout<<"\033[38;5;205mEnter s1 ans s2\033[0m"<<endl;
cin>>s1>>s2;
cout<<"s1:  "<<s1<<"  s2:   "<<s2<<endl<<endl;

cout<<"\033[38;5;205mstrcpy\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
strcpy(temp,s2);
cout<<temp<<endl<<endl;

cout<<"\033[38;5;205mstrncpy\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
strncpy(temp,s2,3);
cout<<temp<<endl<<endl;

cout<<"\033[38;5;205mstrcmp\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
if(strcmp(s1,s2)==0)
cout<<"Equal"<<endl<<endl;
else
cout<<"Not Equal"<<endl<<endl;


cout<<"\033[38;5;205mstrncmp\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
if(strncmp(s1,s2,3)==0)
cout<<"Equal"<<endl<<endl;
else
cout<<"Not Equal"<<endl<<endl;

temp=s1;
cout<<"\033[38;5;205mstrcat\033[0m"<<endl;
cout<<"s1:  "<<temp<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
strcat(temp,s2);
cout<<temp<<endl<<endl;

temp=s1;
cout<<"\033[38;5;205mstrncat\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
temp1=strncat(temp,s2,3);
cout<<temp<<endl<<endl;

temp=s1;
cout<<"\033[38;5;205mstrrev\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
cout<<strrev(temp)<<endl<<endl;

temp=s1;
cout<<"\033[38;5;205mstrupper\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
cout<<strupper(temp)<<endl<<endl;

temp=s1;
cout<<"\033[38;5;205mstrlower\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
cout<<strlower(temp)<<endl<<endl;

cout<<"\033[38;5;205mstrchr\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
if(strchr(s1,'c'))
cout<<"char found"<<endl<<endl;
else
cout<<"char not found"<<endl<<endl;

cout<<"\033[38;5;205mstrrchr\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
if(strrchr(s1,'c'))
cout<<"char found"<<endl<<endl;
else
cout<<"char not found"<<endl<<endl;

cout<<"\033[38;5;205mstrstr\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
if(strstr(s1,s2))
cout<<strstr(s1,s2)<<endl<<endl;
else
cout<<"string not found"<<endl<<endl;

cout<<"\033[38;5;205mstrlen\033[0m"<<endl;
cout<<"s1:  "<<s1<<"  s2:  "<<s2<<endl;
cout<<"Result:  "<<endl;
cout<<strlen(s1)<<endl<<endl;
}
