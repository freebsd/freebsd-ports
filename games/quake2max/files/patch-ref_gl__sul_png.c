--- ref_gl/sul_png.c.orig	2005-12-27 10:57:45.000000000 +0100
+++ ref_gl/sul_png.c	2012-04-29 06:53:31.000000000 +0200
@@ -177,7 +177,7 @@
 		return;
 	}
 
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 		free(rgbdata);
