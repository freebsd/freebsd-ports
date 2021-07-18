--- library/stdarch/crates/std_detect/src/detect/os/freebsd/aarch64.rs.orig	2021-06-16 15:22:56 UTC
+++ library/stdarch/crates/std_detect/src/detect/os/freebsd/aarch64.rs
@@ -1,6 +1,6 @@
 //! Run-time feature detection for Aarch64 on FreeBSD.
 
-pub use super::super::aarch64::detect_features;
+pub(crate) use super::super::aarch64::detect_features;
 
 #[cfg(test)]
 mod tests {
