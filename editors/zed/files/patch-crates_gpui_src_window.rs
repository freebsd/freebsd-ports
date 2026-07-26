--- crates/gpui/src/window.rs.orig	2026-07-25 22:33:53 UTC
+++ crates/gpui/src/window.rs
@@ -2010,7 +2010,7 @@ impl Window {
     /// This is only needed to disambiguate a corner-anchored surface; otherwise the
     /// edge is deduced from the anchor. The edge must be a single edge the surface
     /// is anchored to, or it is ignored. (Wayland layer-shell windows only)
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     pub fn set_exclusive_edge(&self, edge: crate::layer_shell::Anchor) {
         self.platform_window.set_exclusive_edge(edge);
     }
