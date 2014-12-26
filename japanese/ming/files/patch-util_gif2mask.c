--- ../util/gif2mask.c.orig	2002-06-24 12:21:54.000000000 +0000
+++ ../util/gif2mask.c	2014-12-26 17:30:23.000000000 +0000
@@ -11,7 +11,6 @@
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
   exit(-1);
 }
 
@@ -23,7 +22,11 @@ unsigned char *readGif(char *fileName, i
   unsigned char *data;
   int i, nColors, size;
 
+#if GIFLIB_MAJOR >= 5
+  if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
   if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
