--- crates/gpui_linux/src/linux/platform.rs.orig	2026-11-04 15:12:45 UTC
+++ crates/gpui_linux/src/linux/platform.rs
@@ -100,7 +100,7 @@ pub(crate) struct LinuxCommon {
     app_name: Option<String>,
     system_notifications: crate::linux::system_notifications::SystemNotificationState,
     #[cfg_attr(
-        not(all(target_os = "linux", any(feature = "wayland", feature = "x11"))),
+        not(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11"))),
         allow(dead_code)
     )]
     power_sender: Sender<SystemPowerEvent>,
