--- vendor/libc-0.2.93/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig	2020-03-17 20:35:43 UTC
+++ vendor/libc-0.2.93/src/unix/bsd/freebsdlike/freebsd/mod.rs
@@ -1486,6 +1486,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "powerpc64")] {
         mod powerpc64;
         pub use self::powerpc64::*;
+    } else if #[cfg(target_arch = "powerpc")] {
+        mod powerpc;
+        pub use self::powerpc::*;
     } else {
         // Unknown target_arch
     }
