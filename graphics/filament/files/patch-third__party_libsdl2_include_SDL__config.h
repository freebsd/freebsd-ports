--- third_party/libsdl2/include/SDL_config.h.orig	2022-08-19 18:37:12 UTC
+++ third_party/libsdl2/include/SDL_config.h
@@ -41,7 +41,7 @@
 #include "SDL_config_android.h"
 #elif defined(__PSP__)
 #include "SDL_config_psp.h"
-#elif defined(__LINUX__)
+#elif defined(__LINUX__) || defined(__FreeBSD__)
 #if defined(FILAMENT_SUPPORTS_WAYLAND)
 #include "SDL_config_linux_wayland.h"
 #elif defined(FILAMENT_SUPPORTS_X11)
