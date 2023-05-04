--- ui/ozone/platform/wayland/host/wayland_toplevel_window.h.orig	2023-03-30 00:34:19 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.h
@@ -250,7 +250,7 @@ class WaylandToplevelWindow : public WaylandWindow,
   // Contains the previous state of the window.
   PlatformWindowState previous_state_ = PlatformWindowState::kUnknown;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Contains the current state of the tiled edges.
   WindowTiledEdges tiled_state_;
 #endif
