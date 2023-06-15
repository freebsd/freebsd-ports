--- src/SDL_gpu.c.orig	2023-06-15 09:35:37 UTC
+++ src/SDL_gpu.c
@@ -1090,10 +1090,10 @@ static SDL_Surface* gpu_copy_raw_surface_data(unsigned
         break;
     case 4:
 #if SDL_BYTEORDER == SDL_BIG_ENDIAN
-        rmask = 0xff000000;
-        gmask = 0x00ff0000;
-        bmask = 0x0000ff00;
-        amask = 0x000000ff;
+        Rmask = 0xff000000;
+        Gmask = 0x00ff0000;
+        Bmask = 0x0000ff00;
+        Amask = 0x000000ff;
 #else
         Rmask = 0x000000ff;
         Gmask = 0x0000ff00;
