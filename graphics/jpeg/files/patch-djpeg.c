--- djpeg.c.orig	Sat Oct 11 18:29:07 1997
+++ djpeg.c	Mon Apr 24 16:04:13 2000
@@ -26,6 +26,7 @@
 #include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
 #include "jversion.h"		/* for version message */
 
+#include <locale.h>		/* to declare setlocal() */
 #include <ctype.h>		/* to declare isprint() */
 
 #ifdef USE_CCOMMAND		/* command-line reader for Macintosh */
@@ -385,6 +386,9 @@
 	      cinfo->unread_marker - JPEG_APP0, (long) length);
   }
 
+  if (traceit) {
+    setlocale(LC_ALL, "");
+  }
   while (--length >= 0) {
     ch = jpeg_getc(cinfo);
     if (traceit) {
