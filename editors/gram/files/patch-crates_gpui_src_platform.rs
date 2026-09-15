--- crates/gpui/src/platform.rs.orig	2026-08-25 07:40:58 UTC
+++ crates/gpui/src/platform.rs
@@ -69,7 +69,7 @@ pub(crate) use windows::*;
 #[cfg(target_os = "windows")]
 pub(crate) use windows::*;
 
-#[cfg(all(target_os = "linux", feature = "wayland"))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
 pub use linux::layer_shell;
 
 #[cfg(any(test, feature = "test-support"))]
@@ -1243,7 +1243,7 @@ pub enum WindowKind {
 
     /// A Wayland LayerShell window, used to draw overlays or backgrounds for applications such as
     /// docks, notifications or wallpapers.
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     LayerShell(layer_shell::LayerShellOptions),
 }
 
