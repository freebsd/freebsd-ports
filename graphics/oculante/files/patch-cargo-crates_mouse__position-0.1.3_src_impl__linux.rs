--- cargo-crates/mouse_position-0.1.3/src/impl_linux.rs.orig	2024-05-20 06:17:51 UTC
+++ cargo-crates/mouse_position-0.1.3/src/impl_linux.rs
@@ -1,8 +1,8 @@
 //! Implementation for Linux.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use crate::mouse_position::Mouse;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 impl Mouse {
     pub fn get_mouse_position() -> Mouse {
         use x11_dl::xlib;
