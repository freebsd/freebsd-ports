--- converter/other/pnmtotiffcmyk.c.orig	Sat May 13 09:29:45 2000
+++ converter/other/pnmtotiffcmyk.c	Tue Jun 18 00:00:00 2002
@@ -71,8 +71,12 @@
 #define VERSION 1.01
 
 /* beware - these evaluate more than once */
+#ifndef MAX
 #define MAX(x, y) ( ( x ) > ( y ) ? ( x ) : ( y ) )
+#endif
+#ifndef MIN
 #define MIN(x, y) ( ( x ) < ( y ) ? ( x ) : ( y ) )
+#endif
 
 /* only support 8 bit values */
 #define MAXTIFFBITS 8
