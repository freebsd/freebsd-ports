--- ui/ozone/platform/wayland/host/wayland_toplevel_window.h.orig	2023-10-19 19:59:21 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.h
@@ -244,7 +244,7 @@ class WaylandToplevelWindow : public WaylandWindow,
   // Contains the previous state of the window.
   PlatformWindowState previous_state_ = PlatformWindowState::kUnknown;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Contains the current state of the tiled edges.
   WindowTiledEdges tiled_state_;
 #endif
