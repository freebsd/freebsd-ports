--- gdc.c.orig	Mon Jun  4 02:41:42 2001
+++ gdc.c	Mon Jun  4 02:41:51 2001
@@ -158,7 +158,7 @@
 	if( GDC_generate_gif )
 		{
 		fflush(fptr);			// clear anything buffered 
-		gdImageGif(im, fptr);
+		gdImagePng(im, fptr);
 		}
 
 	if( GDC_hold_img & GDC_EXPOSE_IMAGE )
