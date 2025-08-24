--- src/Layers/xrRender/dxImGuiRender.cpp.orig	2025-07-20 11:05:19 UTC
+++ src/Layers/xrRender/dxImGuiRender.cpp
@@ -5,7 +5,7 @@
 #if defined(USE_DX11)
 #include <backends/imgui_impl_dx11.h>
 #elif defined(USE_OGL)
-#include <backends/imgui_impl_opengl3.h>
+#include <imgui_impl_opengl3.h>
 #endif
 
 namespace xray::render::RENDER_NAMESPACE
