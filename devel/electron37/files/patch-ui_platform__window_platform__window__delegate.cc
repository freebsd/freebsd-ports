--- ui/platform_window/platform_window_delegate.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -56,7 +56,7 @@ gfx::Insets PlatformWindowDelegate::CalculateInsetsInD
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
