--- cargo-crates/cosmic-text-0.12.1/src/font/fallback/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cosmic-text-0.12.1/src/font/fallback/mod.rs
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
 
