--- main.cpp.orig	2022-12-31 03:50:49 UTC
+++ main.cpp
@@ -29,7 +29,7 @@ using namespace std;
 
 /***** main program entry point ********************/
 
-int main(int /*argc*/,char /***args*/) {
+int main(int /*argc*/,char **/*args*/) {
 	CKingdom kingdom;
 	
 	#ifndef _WIN32
