-- Add FreeBSD support to device_query crate (x11 input, build config, module selection).
--- cargo-crates/device_query-1.1.3/src/device_state/mod.rs.orig	2026-09-27 23:28:22 UTC
+++ cargo-crates/device_query-1.1.3/src/device_state/mod.rs
@@ -1,8 +1,8 @@
 //! DeviceState implementation.
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod linux;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub use self::linux::DeviceState;
 
 #[cfg(target_os = "windows")]
