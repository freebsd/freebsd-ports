--- vendor/msf_gif/msf_gif.h.orig	2026-01-15 17:48:46 UTC
+++ vendor/msf_gif/msf_gif.h
@@ -560,7 +560,7 @@ int msf_gif_begin(MsfGifState * handle, int width, int
 int msf_gif_begin(MsfGifState * handle, int width, int height) { MsfTimeFunc
     //To help avoid potential overflow errors, let's just not even try to support images larger than 1GB in size.
     //And let's also reject images with width or height more or less than what the gif format itself supports.
-    const int MAX_PIXELS = 268'435'456; //2^30 / 4 = 1GB / bytesPerPixel
+    const int MAX_PIXELS = 268435456; //2^30 / 4 = 1GB / bytesPerPixel
     if (width < 1 || height < 1 || width > 65535 || height > 65535 || width >= MAX_PIXELS / height) {
         handle->listHead = NULL; //this implicitly marks the handle as invalid until the next msf_gif_begin() call
         return 0;
