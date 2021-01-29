--- src/libimage/gif.c.orig	2021-01-27 08:42:58.763140000 -0800
+++ src/libimage/gif.c	2021-01-27 08:45:43.718031000 -0800
@@ -179,7 +179,7 @@
 	}
     }
     
-    if (DGifCloseFile(GifFile) == GIF_ERROR) {
+    if (DGifCloseFile(GifFile, NULL) == GIF_ERROR) {
 	return(0);
     }
 
@@ -493,7 +493,7 @@
 static void QuitGifError(GifFileType *GifFile)
 {
     fprintf(stderr, "Error writing GIF file\n");
-    if (GifFile != NULL) EGifCloseFile(GifFile);
+    if (GifFile != NULL) EGifCloseFile(GifFile, NULL);
 }
 
 int 
@@ -589,7 +589,7 @@
 	Ptr += width;
     }
 
-    if (EGifCloseFile(GifFile) == GIF_ERROR)
+    if (EGifCloseFile(GifFile, NULL) == GIF_ERROR)
 
     {
 	QuitGifError(GifFile);
