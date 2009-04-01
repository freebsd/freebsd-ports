--- chr.c.orig	2009-03-03 16:47:01.000000000 +0200
+++ chr.c	2009-03-03 16:47:09.000000000 +0200
@@ -15,11 +15,6 @@
 
 #define BSLASH	'\134'
 
-struct CHR_SYM {
-  char *str;
-  char chr;
-};
-
 struct CHR_SYM csym[] = {
   { "null", 		0 },
   { "bell",			'\a' }, 
