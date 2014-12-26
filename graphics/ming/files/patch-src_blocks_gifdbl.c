--- src/blocks/gifdbl.c.orig	2010-10-10 07:19:23 UTC
+++ src/blocks/gifdbl.c
@@ -227,7 +227,11 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
+#if GIFLIB_MAJOR >= 5
+	if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
 	if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
@@ -246,7 +250,11 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
+#if GIFLIB_MAJOR >= 5
+	if((file = DGifOpen(input, (InputFunc) gifReadFunc, NULL)) == NULL)
+#else
 	if((file = DGifOpen(input, (InputFunc) gifReadFunc)) == NULL)
+#endif
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
