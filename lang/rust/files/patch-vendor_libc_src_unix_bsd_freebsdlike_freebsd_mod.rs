--- vendor/libc/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig	2019-04-08 14:18:24 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/freebsd/mod.rs
@@ -1155,6 +1155,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "aarch64")] {
         mod aarch64;
         pub use self::aarch64::*;
+    } else if #[cfg(target_arch = "arm")] {
+        mod arm;
+        pub use self::arm::*;
+    } else if #[cfg(target_arch = "powerpc64")] {
+        mod powerpc64;
+        pub use self::powerpc64::*;
     } else {
         // Unknown target_arch
     }
