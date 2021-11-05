--- vendor/libc-0.2.98/src/unix/bsd/freebsdlike/freebsd/freebsd13/mod.rs.orig	2021-11-29 20:27:33 UTC
+++ vendor/libc-0.2.98/src/unix/bsd/freebsdlike/freebsd/freebsd13/mod.rs
@@ -240,7 +240,8 @@ extern "C" {
 
 cfg_if! {
     if #[cfg(any(target_arch = "x86_64",
-                 target_arch = "aarch64"))] {
+                 target_arch = "aarch64",
+                 target_arch = "riscv64"))] {
         mod b64;
         pub use self::b64::*;
     }
