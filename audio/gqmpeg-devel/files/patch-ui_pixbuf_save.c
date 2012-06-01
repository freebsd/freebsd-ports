--- src/ui_pixbuf_save.c.orig	2002-03-09 20:00:13.000000000 +0100
+++ src/ui_pixbuf_save.c	2012-05-09 13:04:57.000000000 +0200
@@ -24,6 +24,7 @@
 
 #ifdef HAVE_LIBPNG
 #include <png.h>	/* for png saving, below */
+#include <pngpriv.h>
 #endif
 
 
@@ -86,7 +87,7 @@
 	    	return FALSE;
 		}
 
-	if (setjmp (png_ptr->jmpbuf))
+	if (setjmp (png_ptr->longjmp_buffer))
 		{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (handle);
