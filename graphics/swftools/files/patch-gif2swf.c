--- src/gif2swf.c.orig	2011-01-02 04:30:29.000000000 +0100
+++ src/gif2swf.c	2012-06-03 06:43:44.000000000 +0200
@@ -65,6 +65,16 @@
     RESTORE_TO_PREVIOUS
 };
 
+static void
+localPrintGifError(void)
+{
+    char *Err = GifErrorString();
+
+    if (Err != NULL)
+        fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+        fprintf(stderr, "\nGIF-LIB undefined error %d.\n", GifError());
+}
 
 void SetFrameAction(TAG ** t, const char *src, int ver)
 {
@@ -236,7 +246,7 @@
     }
 
     if (DGifSlurp(gft) != GIF_OK) {
-        PrintGifError();
+        localPrintGifError();
         return t;
     }
 
@@ -499,7 +509,7 @@
         global.max_image_height = gft->SHeight;
 
     if (DGifSlurp(gft) != GIF_OK) { 
-        PrintGifError();
+        localPrintGifError();
         return -1;
     }
     // After DGifSlurp() call, gft->ImageCount become available
