--- cargo-crates/libc-0.2.71/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig	2020-05-26 15:41:18 UTC
+++ cargo-crates/libc-0.2.71/src/unix/bsd/freebsdlike/freebsd/mod.rs
@@ -1511,6 +1511,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "powerpc64")] {
         mod powerpc64;
         pub use self::powerpc64::*;
+    } else if #[cfg(target_arch = "powerpc")] {
+        mod powerpc;
+        pub use self::powerpc::*;
     } else {
         // Unknown target_arch
     }
