
$FreeBSD$

--- src/chemeq.cc.orig	Thu May 10 19:10:19 2001
+++ src/chemeq.cc	Sat Mar  8 21:59:37 2003
@@ -150,7 +150,7 @@
   if (suiv) suiv->compte(c,mult);
 };
 
-void AtomeListe::numerote(int n=0){
+void AtomeListe::numerote(int n){
   if(Zed!=0){ /* cas où ce n'est pas un groupe */
     no = n;
   }
@@ -245,7 +245,7 @@
   nb.simplifie();
 }
 
-bool Molec::printNernst(ostream & o, char * prefix =""){
+bool Molec::printNernst(ostream & o, char * prefix){
   switch(t){
   case sol : return 0;
   case aqueous :
