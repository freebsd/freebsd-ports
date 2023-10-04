--- src/image-load-cr3.cc.orig	2023-06-17 12:14:12 UTC
+++ src/image-load-cr3.cc
@@ -350,7 +350,7 @@ static gboolean image_loader_cr3_load (gpointer loader
         jerr.error = error;
 
 
-	if (setjmp(jerr.setjmp_buffer))
+	if (sigsetjmp(jerr.setjmp_buffer, 0))
 		{
 		/* If we get here, the JPEG code has signaled an error.
 		 * We need to clean up the JPEG object, close the input file, and return.
