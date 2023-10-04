--- src/image-load-jpeg.cc.orig	2023-06-17 12:14:12 UTC
+++ src/image-load-jpeg.cc
@@ -311,7 +311,7 @@ static gboolean image_loader_jpeg_load (gpointer loade
         jerr.error = error;
 
 
-	if (setjmp(jerr.setjmp_buffer))
+	if (sigsetjmp(jerr.setjmp_buffer, 0))
 		{
 		/* If we get here, the JPEG code has signaled an error.
 		 * We need to clean up the JPEG object, close the input file, and return.
