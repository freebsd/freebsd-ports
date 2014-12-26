--- ../util/gif2dbl.c.orig	2002-06-24 12:21:54.000000000 +0000
+++ ../util/gif2dbl.c	2014-12-26 17:29:52.000000000 +0000
@@ -16,7 +16,6 @@
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
   exit(-1);
 }
 
@@ -50,7 +49,11 @@ unsigned char *readGif(char *fileName, i
   unsigned char *p;
   int i, nColors, size, alpha, bgColor, alignedWidth;
 
+#if GIFLIB_MAJOR >= 5
+  if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
   if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
