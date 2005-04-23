--- src/str.cpp.orig	Sat Jan  1 14:43:20 2005
+++ src/str.cpp	Sat Jan  1 14:43:25 2005
@@ -11,7 +11,7 @@
 
 const char Str::nul = '\0';
 
-Str::Str(const char * string=NULL){
+Str::Str(const char * string){
   s=NULL;
   set(string);
 }
@@ -25,7 +25,7 @@
   if (s) delete[] s;
 }
 
-void Str::set(const char * string=NULL){
+void Str::set(const char * string){
   if (s) delete[] s;
   if (string){
     s=new char[strlen(string)+1];
@@ -71,7 +71,7 @@
   return (strlen(s));
 }
 
-bool Str::isEqual(Str * str, bool case_sensitive = true){
+bool Str::isEqual(Str * str, bool case_sensitive){
   if (case_sensitive){
     return (!strcmp(s, str->s));
   }
