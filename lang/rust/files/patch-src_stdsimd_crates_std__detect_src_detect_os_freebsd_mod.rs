--- src/stdsimd/crates/std_detect/src/detect/os/freebsd/mod.rs.orig	2019-04-24 21:07:30 UTC
+++ src/stdsimd/crates/std_detect/src/detect/os/freebsd/mod.rs
@@ -1,9 +1,17 @@
 //! Run-time feature detection on FreeBSD
 
+mod auxvec;
+
 cfg_if! {
     if #[cfg(target_arch = "aarch64")] {
         mod aarch64;
         pub use self::aarch64::check_for;
+    } else if #[cfg(target_arch = "arm")] {
+        mod arm;
+        pub use self::arm::check_for;
+    } else if #[cfg(target_arch = "powerpc64")] {
+        mod powerpc;
+        pub use self::powerpc::check_for;
     } else {
         use arch::detect::Feature;
         /// Performs run-time feature detection.
