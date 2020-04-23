--- src/stdarch/crates/std_detect/src/detect/mod.rs.orig	2020-04-21 17:12:47 UTC
+++ src/stdarch/crates/std_detect/src/detect/mod.rs
@@ -100,7 +100,7 @@ cfg_if! {
     } else if #[cfg(all(target_os = "linux", feature = "use_std"))] {
         #[path = "os/linux/mod.rs"]
         mod os;
-    } else if #[cfg(target_os = "freebsd")] {
+    } else if #[cfg(all(target_os = "freebsd", feature = "use_std"))] {
         #[cfg(target_arch = "aarch64")]
         #[path = "os/aarch64.rs"]
         mod aarch64;
