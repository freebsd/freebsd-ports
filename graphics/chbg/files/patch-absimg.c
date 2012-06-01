--- src/absimg.c.orig	2001-01-08 19:42:18.000000000 +0100
+++ src/absimg.c	2012-05-09 12:34:28.000000000 +0200
@@ -96,7 +96,7 @@
 	
 	pngi = png_create_info_struct(pngw);
 	
-	if (setjmp(pngw->jmpbuf))
+	if (setjmp(png_jmpbuf(pngw)))
 	{
 		png_destroy_write_struct(&pngw, &pngi);
 		fclose(f);
