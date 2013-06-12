--- hmconv1.0pl3.c.orig	1996-07-22 23:16:14.000000000 -0400
+++ hmconv1.0pl3.c	2013-06-12 14:24:05.000000000 -0400
@@ -46,6 +46,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #define isksc(c)   ( (unsigned char) (c) > (unsigned char) '\240'   && \
@@ -125,6 +126,7 @@
 }
 
 #ifndef KNR
+int
 main (int argc, char **argv)
 #else
 main (argc,argv)
@@ -208,7 +210,7 @@
 
       if ( !ishangul) {     /* KSC 5601 doesn't appear, yet */
          fputs((char *) line,out);   /* no conversion */
-         return;
+         return(0);
       }
 
 
