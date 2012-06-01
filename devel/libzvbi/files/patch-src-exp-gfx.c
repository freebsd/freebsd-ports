--- src/exp-gfx.c.orig	2008-02-24 15:17:47.000000000 +0100
+++ src/exp-gfx.c	2012-05-26 12:49:12.000000000 +0200
@@ -1672,11 +1672,11 @@
 	char title[80];
 	unsigned int i;
 
-	if (setjmp (png_ptr->jmpbuf))
+	if (setjmp (png_jmpbuf(png_ptr)))
 		return FALSE;
 
 	png_set_write_fn (png_ptr,
-			  (voidp) gfx,
+			  gfx,
 			  write_data,
 			  flush_data);
 
