--- ./src/cuyo.cpp.orig	2012-01-17 14:47:38.000000000 +0100
+++ ./src/cuyo.cpp	2014-02-01 18:48:07.000000000 +0100
@@ -53,6 +53,7 @@
 /* # Zeitschritte, die nach der Zeitbonus-Animation noch gewartet wird */
 #define nachbonus_wartezeit 50
 
+char * ngettext (char * msgid, const char * msgid_plural, unsigned long int n) {return msgid;}
 
 
 
