--- src/system_info.rs.orig	2023-01-06 17:40:16 UTC
+++ src/system_info.rs
@@ -8,6 +8,11 @@ pub fn platform_name() -> &'static str {
     "linux"
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn platform_name() -> &'static str {
+    "freebsd"
+}
+
 #[cfg(all(
     target_pointer_width = "32",
     any(target_arch = "arm", target_arch = "aarch64")
