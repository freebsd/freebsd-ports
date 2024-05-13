--- pueue_lib/src/process_helper/mod.rs.orig	2024-05-13 20:23:05 UTC
+++ pueue_lib/src/process_helper/mod.rs
@@ -21,6 +21,7 @@ use command_group::Signal;
 #[cfg_attr(target_os = "linux", path = "linux.rs")]
 #[cfg_attr(target_vendor = "apple", path = "apple.rs")]
 #[cfg_attr(target_os = "windows", path = "windows.rs")]
+#[cfg_attr(target_os = "freebsd", path = "freebsd.rs")]
 mod platform;
 pub use self::platform::*;
 
