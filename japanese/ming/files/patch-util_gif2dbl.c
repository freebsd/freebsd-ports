--- ../util/gif2dbl.c.orig	2002-06-24 12:21:54 UTC
+++ ../util/gif2dbl.c
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
@@ -181,7 +184,11 @@ unsigned char *readGif(char *fileName, i
   }
 
 	/* Done! */
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  DGifCloseFile(file, NULL);
+#else
   DGifCloseFile(file);
+#endif
 
   *length = size;
   return data;
