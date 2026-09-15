--- crates/gpui/src/platform/linux/wayland/window.rs.orig	2026-08-25 07:40:58 UTC
+++ crates/gpui/src/platform/linux/wayland/window.rs
@@ -168,7 +168,7 @@ impl WaylandSurfaceState {
             }
 
             if let Some(exclusive_edge) = options.exclusive_edge {
-                layer_surface.set_exclusive_edge(exclusive_edge.into());
+                layer_surface.set_exclusive_edge(zwlr_layer_surface_v1::Anchor::from(exclusive_edge));
             }
 
             return Ok(WaylandSurfaceState::LayerShell(WaylandLayerSurfaceState {
