--- src/getopt.c.orig	Sun Jun 13 00:06:12 2004
+++ src/getopt.c	Sun Jun 13 00:07:48 2004
@@ -36,8 +36,6 @@
  * enables hexcurse to be compiled with SGI's proprietary compiler        */
 #ifdef _SGIAPI
 #include <alloca.h>
-#else
-char *alloca ();
 #endif
 #define __alloca      alloca
 /* end of modification */
