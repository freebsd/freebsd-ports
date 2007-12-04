--- term.c.orig	2007-12-04 15:42:55.000000000 +0300
+++ term.c	2007-12-04 15:43:04.000000000 +0300
@@ -85,7 +85,7 @@
 
 char *termcap_ptr;
 
-int termcap_putter(char ch) {
+int termcap_putter(int ch) {
     *termcap_ptr++ = ch;
     return 0;
 }
