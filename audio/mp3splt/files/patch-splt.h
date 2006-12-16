--- splt.h.orig	Fri Dec 15 19:27:18 2006
+++ splt.h	Fri Dec 15 19:27:40 2006
@@ -93,7 +93,7 @@
 
 char *zero_pad_float (float f, char *out);
 
-int parse_outformat(char *s, char format[][], int cddboption);
+int parse_outformat(char *s, char format[OUTNUM][MAXOLEN], int cddboption);
 
 unsigned char *cleanstring (unsigned char *s);
 
