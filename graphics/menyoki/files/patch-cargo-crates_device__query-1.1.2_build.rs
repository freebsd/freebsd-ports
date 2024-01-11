--- cargo-crates/device_query-1.1.2/build.rs.orig	2024-01-10 23:04:50 UTC
+++ cargo-crates/device_query-1.1.2/build.rs
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
