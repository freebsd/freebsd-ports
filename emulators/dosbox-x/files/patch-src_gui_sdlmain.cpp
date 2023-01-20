--- src/gui/sdlmain.cpp.orig	2023-01-20 21:33:36 UTC
+++ src/gui/sdlmain.cpp
@@ -221,7 +221,7 @@ typedef enum PROCESS_DPI_AWARENESS {
 extern "C" void sdl1_hax_macosx_highdpi_set_enable(const bool enable);
 #endif
 
-#if !defined(C_SDL2) && !defined(RISCOS)
+#if !defined(C_SDL2) && !defined(RISCOS) && !defined(__FreeBSD__)
 # include "SDL_version.h"
 # ifndef SDL_DOSBOX_X_SPECIAL
 #  warning It is STRONGLY RECOMMENDED to compile the DOSBox-X code using the SDL 1.x library provided in this source repository.
