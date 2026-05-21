--- builder/src/arch/mod.rs.orig	2025-11-24 20:38:29.000000000 +0100
+++ builder/src/arch/mod.rs	2026-05-21 11:08:08.882738000 +0200
@@ -28,3 +28,8 @@
 #[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
 #[cfg(target_os = "windows")]
 pub use crate::arch::windows::*;
+
+#[cfg(target_os = "freebsd")]
+pub mod freebsd;
+#[cfg(target_os = "freebsd")]
+pub use crate::arch::freebsd::*;
