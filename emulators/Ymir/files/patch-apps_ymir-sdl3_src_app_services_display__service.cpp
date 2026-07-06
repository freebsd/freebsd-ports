--- apps/ymir-sdl3/src/app/services/display_service.cpp.orig	2026-06-21 23:44:48 UTC
+++ apps/ymir-sdl3/src/app/services/display_service.cpp
@@ -9,8 +9,8 @@
 #include <ymir/util/scope_guard.hpp>

 #include <SDL3/SDL.h>
-#include <backends/imgui_impl_sdl3.h>
-#include <backends/imgui_impl_sdlrenderer3.h>
+#include <imgui_impl_sdl3.h>
+#include <imgui_impl_sdlrenderer3.h>
 #include <cmrc/cmrc.hpp>
 #include <imgui.h>
