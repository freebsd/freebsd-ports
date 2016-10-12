--- src/video/sdl/vga_sdl.cpp.orig	2016-09-04 17:31:41 UTC
+++ src/video/sdl/vga_sdl.cpp
@@ -58,7 +58,8 @@ VgaSDL::VgaSDL()
 
 VgaSDL::~VgaSDL()
 {
-   deinit();
+   if (window != NULL)
+      deinit();
 }
 //-------- End of function VgaSDL::~VgaSDL ----------//
 
