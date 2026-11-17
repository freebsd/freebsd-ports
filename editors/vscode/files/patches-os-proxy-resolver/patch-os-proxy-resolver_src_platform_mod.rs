--- os-proxy-resolver/src/platform/mod.rs.orig	2026-09-06 06:15:05 UTC
+++ os-proxy-resolver/src/platform/mod.rs
@@ -19,7 +19,7 @@ mod imp;
 #[cfg(target_os = "macos")]
 #[path = "macos.rs"]
 mod imp;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[path = "linux.rs"]
 mod imp;
 #[cfg(windows)]
