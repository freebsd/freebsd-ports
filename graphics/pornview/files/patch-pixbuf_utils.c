--- src/support/pixbuf_utils.c.orig	2002-12-13 13:29:28.000000000 +0100
+++ src/support/pixbuf_utils.c	2012-05-09 12:38:26.000000000 +0200
@@ -18,6 +18,7 @@
 #endif
 
 #include <png.h>
+#include <pngpriv.h>
 #include <gtk/gtk.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
 
@@ -60,7 +61,7 @@
 	return FALSE;
     }
 
-    if (setjmp (png_ptr->jmpbuf))
+    if (setjmp (png_jmpbuf(png_ptr)))
     {
 	png_destroy_write_struct (&png_ptr, &info_ptr);
 	fclose (handle);
