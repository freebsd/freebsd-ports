--- src/video_yuv.c.orig	2003-04-03 13:27:29 UTC
+++ src/video_yuv.c
@@ -25,6 +25,10 @@
 #include "memory.h"
 #include "message.h"
 
+Uint32 yuv_flag;
+SDL_Overlay *overlay;
+yuv_t rgb2yuv[65536];
+
 void init_message_yuv(void) {
 
 }
