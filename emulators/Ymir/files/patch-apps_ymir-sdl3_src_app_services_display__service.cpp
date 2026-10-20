--- apps/ymir-sdl3/src/app/services/display_service.cpp.orig	2026-10-18 00:13:37 UTC
+++ apps/ymir-sdl3/src/app/services/display_service.cpp
@@ -12,8 +12,8 @@
 
 #include <SDL3/SDL.h>
 
-#include <backends/imgui_impl_sdl3.h>
-#include <backends/imgui_impl_sdlrenderer3.h>
+#include <imgui_impl_sdl3.h>
+#include <imgui_impl_sdlrenderer3.h>
 
 #include <cmrc/cmrc.hpp>
 
