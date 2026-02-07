--- builder/src/arch/mod.rs.orig	2025-02-11 17:46:31 UTC
+++ builder/src/arch/mod.rs
@@ -28,3 +28,10 @@ pub use crate::arch::windows::*;
 #[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
 #[cfg(target_os = "windows")]
 pub use crate::arch::windows::*;
+
+#[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
+#[cfg(target_os = "freebsd")]
+pub mod freebsd;
+#[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
+#[cfg(target_os = "freebsd")]
+pub use crate::arch::freebsd::*;
