--- ref_gl/sul_png.c.orig	2005-12-27 09:57:45 UTC
+++ ref_gl/sul_png.c
@@ -177,7 +177,7 @@ void GL_ScreenShot_PNG (void)
 		return;
 	}
 
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 		free(rgbdata);
