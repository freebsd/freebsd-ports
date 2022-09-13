--- lib/aux_vis.cpp.orig	2022-09-11 23:06:14 UTC
+++ lib/aux_vis.cpp
@@ -822,8 +822,8 @@ const char *glvis_screenshot_ext = ".bmp";
 #if SDL_BYTEORDER == SDL_BIG_ENDIAN
 Uint32 rmask = 0xff000000;
 Uint32 gmask = 0x00ff0000;
-Uint32 bmask = 0x0000ff00:
-               Uint32 amask = 0x000000ff;
+Uint32 bmask = 0x0000ff00;
+Uint32 amask = 0x000000ff;
 #else // little endian, like x86
 Uint32 rmask = 0x000000ff;
 Uint32 gmask = 0x0000ff00;
