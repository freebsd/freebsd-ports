--- vendor/libc-0.2.108/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig	2021-11-29 20:27:33 UTC
+++ vendor/libc-0.2.108/src/unix/bsd/freebsdlike/freebsd/mod.rs
@@ -2021,6 +2021,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "powerpc")] {
         mod powerpc;
         pub use self::powerpc::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
     } else {
         // Unknown target_arch
     }
