--- plug-ins/png/png.c.orig	2006-11-24 21:52:55.000000000 +0100
+++ plug-ins/png/png.c	2012-04-27 19:08:52.000000000 +0200
@@ -59,6 +59,7 @@
 #include "libgimp/stdplugins-intl.h"
 
 #include <png.h>		/* PNG library definitions */
+#include <pngpriv.h>
 
 /*
  * Constants...
@@ -405,7 +406,7 @@
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message ("%s\nPNG error. File corrupted?", filename);
     return image;
@@ -824,7 +825,7 @@
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message ("%s\nPNG error. Couldn't save image", filename);
     return 0;
