--- ui/platform_window/platform_window_delegate.cc.orig	2024-02-21 00:21:16 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -42,7 +42,7 @@ PlatformWindowDelegate::~PlatformWindowDelegate() = de
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
