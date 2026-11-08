--- cargo-crates/tao-0.37.0/src/window.rs.orig	2026-10-10 01:56:11 UTC
+++ cargo-crates/tao-0.37.0/src/window.rs
@@ -1662,7 +1662,7 @@ pub enum ResizeDirection {
   West,
 }
 
-#[cfg(any(target_os = "windows", target_os = "linux"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os="freebsd"))]
 pub(crate) fn hit_test(
   (left, top, right, bottom): (i32, i32, i32, i32),
   cx: i32,
