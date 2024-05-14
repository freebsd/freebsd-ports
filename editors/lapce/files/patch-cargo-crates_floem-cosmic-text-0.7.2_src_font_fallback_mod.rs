https://github.com/lapce/cosmic-text/pull/6

--- cargo-crates/floem-cosmic-text-0.7.2/src/font/fallback/mod.rs.orig	2024-05-09 07:49:44 UTC
+++ cargo-crates/floem-cosmic-text-0.7.2/src/font/fallback/mod.rs
@@ -10,7 +10,7 @@ use self::platform::*;
 
 use self::platform::*;
 
-#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows",)))]
+#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "freebsd",)))]
 #[path = "other.rs"]
 mod platform;
 
@@ -18,7 +18,7 @@ mod platform;
 #[path = "macos.rs"]
 mod platform;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[path = "unix.rs"]
 mod platform;
 
