--- wargus.c.orig	2010-11-22 03:07:16.000000000 +0300
+++ wargus.c	2014-05-16 20:50:55.007540700 +0400
@@ -86,7 +86,7 @@
 int ConsoleMode = 0;
 #endif
 
-inline void error(char * title, char * text) {
+void error(char * title, char * text) {
 
 #ifdef WIN32
 	MessageBox(NULL, text, title, MB_OK | MB_ICONERROR);
