--- ui/platform_window/platform_window_delegate.h.orig	2024-02-21 00:21:16 UTC
+++ ui/platform_window/platform_window_delegate.h
@@ -157,7 +157,7 @@ class COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindow
   virtual void OnWindowStateChanged(PlatformWindowState old_state,
                                     PlatformWindowState new_state) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Notifies the delegate that the tiled state of the window edges has changed.
   virtual void OnWindowTiledStateChanged(WindowTiledEdges new_tiled_edges);
 #endif
