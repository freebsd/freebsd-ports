--- mapimageio.c.orig	2015-07-24 07:59:36 UTC
+++ mapimageio.c
@@ -1058,7 +1058,11 @@ int readGIF(char *path, rasterBufferObj 
 
   } while (recordType != TERMINATE_RECORD_TYPE);
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  if (DGifCloseFile(image, NULL) == GIF_ERROR) {
+#else
   if (DGifCloseFile(image) == GIF_ERROR) {
+#endif
 #if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
     msSetError(MS_MISCERR,"failed to close gif after loading: %s","readGIF()", gif_error_msg(image->Error));
 #else
