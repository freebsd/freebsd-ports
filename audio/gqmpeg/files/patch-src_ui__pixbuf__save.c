--- src/ui_pixbuf_save.c.orig	2002-03-09 19:00:13 UTC
+++ src/ui_pixbuf_save.c
@@ -86,7 +86,7 @@ gboolean pixbuf_to_file_as_png (GdkPixbu
 	    	return FALSE;
 		}
 
-	if (setjmp (png_ptr->jmpbuf))
+	if (setjmp (png_jmpbuf (png_ptr)))
 		{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (handle);
