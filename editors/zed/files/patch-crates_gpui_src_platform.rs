--- crates/gpui/src/platform.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/gpui/src/platform.rs
@@ -2,7 +2,7 @@ mod keystroke;
 mod keyboard;
 mod keystroke;
 
-#[cfg(all(target_os = "linux", feature = "wayland"))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
 #[expect(missing_docs)]
 pub mod layer_shell;
 
@@ -19,7 +19,7 @@ pub mod scap_screen_capture;
 pub mod scap_screen_capture;
 
 #[cfg(all(
-    any(target_os = "windows", target_os = "linux"),
+    any(target_os = "windows", target_os = "linux", target_os = "freebsd"),
     feature = "screen-capture"
 ))]
 pub(crate) type PlatformScreenCaptureFrame = scap::frame::Frame;
@@ -1365,7 +1365,7 @@ pub enum WindowKind {
 
     /// A Wayland LayerShell window, used to draw overlays or backgrounds for applications such as
     /// docks, notifications or wallpapers.
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     LayerShell(layer_shell::LayerShellOptions),
 
     /// A window that appears on top of its parent window and blocks interaction with it
