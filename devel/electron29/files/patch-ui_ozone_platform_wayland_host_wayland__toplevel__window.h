--- ui/ozone/platform/wayland/host/wayland_toplevel_window.h.orig	2024-02-21 00:21:16 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.h
@@ -260,7 +260,7 @@ class WaylandToplevelWindow : public WaylandWindow,
   // The display ID to switch to in case the state is `kFullscreen`.
   int64_t fullscreen_display_id_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Contains the current state of the tiled edges.
   WindowTiledEdges tiled_state_;
 #endif
