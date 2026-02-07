--- src/gui/sdlmain.cpp.orig	2020-03-21 19:17:13 UTC
+++ src/gui/sdlmain.cpp
@@ -1433,7 +1433,7 @@ void GFX_LosingFocus(void) {
 #define DB_POLLSKIP 1
 #endif
 
-#if defined(LINUX)
+#if defined(LINUX) || defined(BSD)
 #define SDL_XORG_FIX 1
 #else
 #define SDL_XORG_FIX 0
