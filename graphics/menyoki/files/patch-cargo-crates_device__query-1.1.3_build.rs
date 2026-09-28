-- Add FreeBSD support to device_query crate (x11 input, build config, module selection).
--- cargo-crates/device_query-1.1.3/build.rs.orig	2026-09-27 23:28:22 UTC
+++ cargo-crates/device_query-1.1.3/build.rs
@@ -6,16 +6,16 @@ fn main() {}
 #[cfg(target_os = "macos")]
 fn main() {}
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::env;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::fs::File;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::io::Write;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::path::Path;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn main() {
     let mut config = String::new();
     let libdir = match pkg_config::get_variable("x11", "libdir") {
