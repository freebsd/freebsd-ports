--- apps/ymir-sdl3/src/app/services/gfx/gfx_context_impl_sdl_renderer.cpp.orig	2026-10-17 23:30:53 UTC
+++ apps/ymir-sdl3/src/app/services/gfx/gfx_context_impl_sdl_renderer.cpp
@@ -2,8 +2,8 @@
 
 #include <fmt/format.h>
 
-#include <backends/imgui_impl_sdl3.h>
-#include <backends/imgui_impl_sdlrenderer3.h>
+#include <imgui_impl_sdl3.h>
+#include <imgui_impl_sdlrenderer3.h>
 
 #include <ymir/util/scope_guard.hpp>
 
