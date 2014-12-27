--- ../util/gif2mask.c.orig	2013-06-08 14:08:51 UTC
+++ ../util/gif2mask.c
@@ -28,7 +28,11 @@ unsigned char *readGif(char *fileName, i
   unsigned char *data;
   int i, nColors, size;
 
+#if GIFLIB_MAJOR >= 5
+  if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
   if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
