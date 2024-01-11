--- cargo-crates/device_query-1.1.2/src/device_state/mod.rs.orig	2024-01-10 23:09:14 UTC
+++ cargo-crates/device_query-1.1.2/src/device_state/mod.rs
@@ -2,8 +2,12 @@ mod linux;
 
 #[cfg(target_os = "linux")]
 mod linux;
+#[cfg(target_os = "freebsd")]
+mod freebsd;
 #[cfg(target_os = "linux")]
 pub use self::linux::DeviceState;
+#[cfg(target_os = "freebsd")]
+pub use self::freebsd::DeviceState;
 
 #[cfg(target_os = "windows")]
 mod windows;
