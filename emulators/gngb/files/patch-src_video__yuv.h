--- src/video_yuv.h.orig	2003-04-03 13:27:29 UTC
+++ src/video_yuv.h
@@ -21,16 +21,18 @@
 
 #include "global.h"
 
-SDL_Overlay *overlay;
-SDL_Rect ov_rect;
-Uint32 yuv_flag;
+extern SDL_Overlay *overlay;
+extern SDL_Rect ov_rect;
+extern Uint32 yuv_flag;
 
-struct yuv{
+typedef struct yuv{
   Uint16 y;
   Uint8  u;
   Uint8  v;
   Uint32 yuy2;
-}rgb2yuv[65536];
+} yuv_t;
+
+extern yuv_t rgb2yuv[65536];
 
 void init_message_yuv(void);
 void init_rgb2yuv_table(void);
