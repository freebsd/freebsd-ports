--- src/ui_pixbuf_save.c.orig	2002-03-09 20:00:13.000000000 +0100
+++ src/ui_pixbuf_save.c	2014-12-23 23:54:56.105240001 +0100
@@ -86,7 +86,7 @@ gboolean pixbuf_to_file_as_png (GdkPixbu
 	    	return FALSE;
 		}
 
-	if (setjmp (png_ptr->jmpbuf))
+	if (setjmp (png_jmpbuf (png_ptr)))
 		{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (handle);
