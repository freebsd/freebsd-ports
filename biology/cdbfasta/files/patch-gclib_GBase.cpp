--- gclib/GBase.cpp.orig	2023-07-10 09:56:17 UTC
+++ gclib/GBase.cpp
@@ -234,7 +234,7 @@ bool GstrEq(const char* a, const char* b) {
 
 bool GstrEq(const char* a, const char* b) {
 	 if (a==NULL || b==NULL) return false;
-	 register int i=0;
+	 int i=0;
 	 while (a[i]==b[i]) {
 		 if (a[i]==0) return true;
 		 ++i;
@@ -244,7 +244,7 @@ bool GstriEq(const char* a, const char* b) {
 
 bool GstriEq(const char* a, const char* b) {
 	 if (a==NULL || b==NULL) return false;
-	 register int i=0;
+	 int i=0;
 	 while (tolower((unsigned char)a[i])==tolower((unsigned char)b[i])) {
 		 if (a[i]==0) return true;
 	 }
@@ -253,7 +253,7 @@ int Gstricmp(const char* a, const char* b, int n) {
 
 int Gstricmp(const char* a, const char* b, int n) {
  if (a==NULL || b==NULL) return a==NULL ? -1 : 1;
- register int ua, ub;
+ int ua, ub;
  if (n<0) {
    while ((*a!=0) && (*b!=0)) {
     ua=tolower((unsigned char)*a);
@@ -662,8 +662,8 @@ int strhash(const char* str){
 
 //hash function used for strings in GHash
 int strhash(const char* str){
-  register int h=0;
-  register int g;
+  int h=0;
+  int g;
   while (*str) {
     h=(h<<4)+*str++;
     g=h&0xF0000000;
