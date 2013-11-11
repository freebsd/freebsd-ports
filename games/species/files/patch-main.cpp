--- ./main.cpp.orig	2013-11-10 23:14:27.000000000 -0200
+++ ./main.cpp	2013-11-10 23:14:37.000000000 -0200
@@ -29,7 +29,7 @@
 
 /***** main program entry point ********************/
 
-int main(int /*argc*/,char /***args*/) {
+int main(int /*argc*/,char ** /*args*/) {
 	CKingdom kingdom;
 	
 	#ifndef _WIN32
