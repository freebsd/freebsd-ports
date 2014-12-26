--- util/gif2dbl.c.orig	2013-06-08 14:08:51 UTC
+++ util/gif2dbl.c
@@ -59,7 +59,11 @@ unsigned char *readGif(char *fileName, i
   unsigned char *p;
   int i, nColors, size, alpha, bgColor, alignedWidth;
 
+#if GIFLIB_MAJOR >= 5
+  if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
   if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
