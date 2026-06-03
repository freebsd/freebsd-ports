--- crates/gpui/src/platform.rs.orig	2026-03-24 22:04:08 UTC
+++ crates/gpui/src/platform.rs
@@ -67,7 +67,7 @@ pub(crate) use windows::*;
 #[cfg(target_os = "windows")]
 pub(crate) use windows::*;
 
-#[cfg(all(target_os = "linux", feature = "wayland"))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
 pub use linux::layer_shell;
 
 #[cfg(any(test, feature = "test-support"))]
@@ -1265,7 +1265,7 @@ pub enum WindowKind {
 
     /// A Wayland LayerShell window, used to draw overlays or backgrounds for applications such as
     /// docks, notifications or wallpapers.
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     LayerShell(layer_shell::LayerShellOptions),
 }
 
