--- src/gif2swf.c.orig	2011-01-02 03:30:29 UTC
+++ src/gif2swf.c
@@ -65,6 +65,25 @@ enum disposal_method {
     RESTORE_TO_PREVIOUS
 };
 
+static void
+#if GIFLIB_MAJOR >= 5
+localPrintGifError(int ErrorCode)
+#else
+localPrintGifError(void)
+#endif
+{
+#if GIFLIB_MAJOR >= 5
+    char *Err = GifErrorString(ErrorCode);
+#else
+    char *Err = GifErrorString();
+    int ErrorCode = GifError();
+#endif
+
+    if (Err != NULL)
+        fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+        fprintf(stderr, "\nGIF-LIB undefined error %d.\n", ErrorCode);
+}
 
 void SetFrameAction(TAG ** t, const char *src, int ver)
 {
@@ -230,13 +249,21 @@ TAG *MovieAddFrame(SWF * swf, TAG * t, c
     }
     fclose(fi);
 
+#if GIFLIB_MAJOR >= 5
+    if ((gft = DGifOpenFileName(sname, NULL)) == NULL) {
+#else
     if ((gft = DGifOpenFileName(sname)) == NULL) {
+#endif
         fprintf(stderr, "%s is not a GIF file!\n", sname);
         return t;
     }
 
     if (DGifSlurp(gft) != GIF_OK) {
-        PrintGifError();
+#if GIFLIB_MAJOR >= 5
+        localPrintGifError(gft->Error);
+#else
+        localPrintGifError();
+#endif
         return t;
     }
 
@@ -455,7 +482,11 @@ TAG *MovieAddFrame(SWF * swf, TAG * t, c
 
     free(pal);
     free(imagedata);
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(gft, NULL);
+#else
     DGifCloseFile(gft);
+#endif
 
     return t;
 }
@@ -488,7 +519,11 @@ int CheckInputFile(char *fname, char **r
     }
     fclose(fi);
 
+#if GIFLIB_MAJOR >= 5
+    if ((gft = DGifOpenFileName(s, NULL)) == NULL) {
+#else
     if ((gft = DGifOpenFileName(s)) == NULL) {
+#endif
         fprintf(stderr, "%s is not a GIF file!\n", fname);
         return -1;
     }
@@ -499,7 +534,11 @@ int CheckInputFile(char *fname, char **r
         global.max_image_height = gft->SHeight;
 
     if (DGifSlurp(gft) != GIF_OK) { 
-        PrintGifError();
+#if GIFLIB_MAJOR >= 5
+        localPrintGifError(gft->Error);
+#else
+        localPrintGifError();
+#endif
         return -1;
     }
     // After DGifSlurp() call, gft->ImageCount become available
@@ -518,7 +557,11 @@ int CheckInputFile(char *fname, char **r
             fprintf(stderr, "frame: %u, delay: %.3f sec\n", i + 1, getGifDelayTime(gft, i) / 100.0);
     }
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(gft, NULL);
+#else
     DGifCloseFile(gft);
+#endif
 
     return 0;
 }
