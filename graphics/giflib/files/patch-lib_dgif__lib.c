--- lib/dgif_lib.c.orig	2016-03-06 10:52:49.090426000 +0100
+++ lib/dgif_lib.c	2016-03-06 10:53:00.938584000 +0100
@@ -764,7 +764,7 @@
     BitsPerPixel = CodeSize;
 
     /* this can only happen on a severely malformed GIF */
-    if (BitsPerPixel > 8 || Private->RunningBits > 32) {
+    if (BitsPerPixel > 8) {
 	GifFile->Error = D_GIF_ERR_READ_FAILED;	/* somewhat bogus error code */
 	return GIF_ERROR;    /* Failed to read Code size. */
     }
