--- ui/platform_window/platform_window_delegate.cc.orig	2024-04-15 20:34:30 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -48,7 +48,7 @@ PlatformWindowDelegate::~PlatformWindowDelegate() = de
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
