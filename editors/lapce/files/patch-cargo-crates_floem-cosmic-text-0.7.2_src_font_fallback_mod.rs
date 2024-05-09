--- cargo-crates/floem-cosmic-text-0.7.2/src/font/fallback/mod.rs.orig	2024-05-09 07:49:44 UTC
+++ cargo-crates/floem-cosmic-text-0.7.2/src/font/fallback/mod.rs
@@ -11,7 +11,7 @@ use self::platform::*;
 use self::platform::*;
 
 #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows",)))]
-#[path = "other.rs"]
+#[path = "unix.rs"]
 mod platform;
 
 #[cfg(target_os = "macos")]
