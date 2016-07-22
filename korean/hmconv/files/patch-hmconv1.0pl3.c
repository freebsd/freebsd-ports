--- hmconv1.0pl3.c.orig	1996-07-23 03:16:14 UTC
+++ hmconv1.0pl3.c
@@ -46,6 +46,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #define isksc(c)   ( (unsigned char) (c) > (unsigned char) '\240'   && \
@@ -125,6 +126,7 @@ char	*optstring;
 }
 
 #ifndef KNR
+int
 main (int argc, char **argv)
 #else
 main (argc,argv)
@@ -208,7 +210,7 @@ int convert()
 
       if ( !ishangul) {     /* KSC 5601 doesn't appear, yet */
          fputs((char *) line,out);   /* no conversion */
-         return;
+         return(0);
       }
 
 
