--- main.cpp.orig
+++ main.cpp
@@ -29,7 +29,7 @@
 
 /***** main program entry point ********************/
 
-int main(int /*argc*/,char /***args*/) {
+int main(int /*argc*/,char **/*args*/) {
 	CKingdom kingdom;
 	
 	#ifndef _WIN32
