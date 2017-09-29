Catch up with https://hg.libsdl.org/SDL/rev/d11daa346140

--- 3rdparty/bgfx/include/bgfxplatform.h.orig	2015-09-30 06:29:01 UTC
+++ 3rdparty/bgfx/include/bgfxplatform.h
@@ -186,7 +186,7 @@ namespace bgfx
 
 #endif // BX_PLATFORM_
 
-#if defined(_SDL_syswm_h)
+#if defined(_SDL_syswm_h) || defined(SDL_syswm_h_)
 // If SDL_syswm.h is included before bgfxplatform.h we can enable SDL window
 // interop convenience code.
 
