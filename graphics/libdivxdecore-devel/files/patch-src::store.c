--- src/store.c.orig	Mon Sep 24 14:37:06 2001
+++ src/store.c	Mon Sep 24 14:37:23 2001
@@ -55,20 +55,19 @@
 /***/
 
 // Purpose: store a frame in yuv format
-void storeframe (unsigned char *src[], int width, int height)
+void storeframe (char *name, unsigned char *src[], int width, int height, int hor_size)
 {
 	int offset = 0;
-	int hor_size = mp4_state->horizontal_size;
 
-  store_yuv (mp4_state->outputname, src[0], offset, width, hor_size, height);
+  store_yuv (name, src[0], offset, width, hor_size, height);
 
   offset >>= 1;
   width >>= 1;
   height >>= 1;
 	hor_size >>= 1;
 
-  store_yuv (mp4_state->outputname, src[1], offset, width, hor_size, height);
-  store_yuv (mp4_state->outputname, src[2], offset, width, hor_size, height);
+  store_yuv (name, src[1], offset, width, hor_size, height);
+  store_yuv (name, src[2], offset, width, hor_size, height);
 }
 
 /***/
