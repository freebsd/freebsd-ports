--- src/hash.cpp.orig	Sat Jan  1 14:48:35 2005
+++ src/hash.cpp	Sat Jan  1 14:50:49 2005
@@ -55,10 +55,12 @@
   return(sum % nbuckets);
 }
 
-Hash::Hash(int bs=256){
+typedef List *ListPtr;
+
+Hash::Hash(int bs){
  int i;
  nbuckets=bs;
- lbuckets=new (List *)[nbuckets];
+ lbuckets=new ListPtr[nbuckets];
 
  for (i=0;i<nbuckets;i++)
    lbuckets[i]=new List();
@@ -99,7 +101,7 @@
   return NotAdded;
 }
 
-Hash::Result Hash::remove(Str * str, bool del=false){
+Hash::Result Hash::remove(Str * str, bool del){
   if (str){
     Index * i;
     List * list=lbuckets[function(str)];
@@ -135,7 +137,7 @@
   return NULL;
 }
 
-void Hash::empty(bool del=true){
+void Hash::empty(bool del){
   int i;
   List * list;
   for (i=0;i<nbuckets;i++){
