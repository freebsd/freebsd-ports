--- vendor/libc/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig
+++ vendor/libc/src/unix/bsd/freebsdlike/freebsd/mod.rs
@@ -1568,6 +1568,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "arm")] {
         mod arm;
         pub use self::arm::*;
+    } else if #[cfg(target_arch = "powerpc")] {
+        mod powerpc;
+        pub use self::powerpc::*;
     } else if #[cfg(target_arch = "powerpc64")] {
         mod powerpc64;
         pub use self::powerpc64::*;
