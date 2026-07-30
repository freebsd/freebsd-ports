-- Reuse the Linux OS module on FreeBSD because cargo-mobile2 does not yet
-- provide a native FreeBSD implementation.
--- cargo-crates/cargo-mobile2-0.22.4/src/os/mod.rs.orig	2026-07-30 17:20:27 UTC
+++ cargo-crates/cargo-mobile2-0.22.4/src/os/mod.rs
@@ -9,9 +9,15 @@ mod linux;
 #[cfg(target_os = "linux")]
 mod linux;
 
+#[cfg(target_os = "freebsd")]
+mod linux;
+
 #[cfg(target_os = "linux")]
 pub use self::linux::*;
 
+#[cfg(target_os = "freebsd")]
+pub use self::linux::*;
+
 #[cfg(windows)]
 mod windows;
 
@@ -19,7 +25,7 @@ pub use self::windows::*;
 pub use self::windows::*;
 
 #[cfg(not(any(target_os = "macos", target_os = "linux", windows)))]
-compile_error!("Host platform not yet supported by cargo-mobile2! We'd love if you made a PR to add support for this platform ❤️");
+//compile_error!("Host platform not yet supported by cargo-mobile2! We'd love if you made a PR to add support for this platform ❤️");
 
 // TODO: we should probably expose common functionality throughout `os` in a
 // less ad-hoc way... since it's really easy to accidentally break things.
