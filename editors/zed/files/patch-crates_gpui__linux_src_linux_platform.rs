--- crates/gpui_linux/src/linux/platform.rs.orig	2026-07-29 14:43:24 UTC
+++ crates/gpui_linux/src/linux/platform.rs
@@ -126,7 +126,7 @@ pub(crate) struct LinuxCommon {
     app_name: Option<String>,
     system_notifications: crate::linux::system_notifications::SystemNotificationState,
     #[cfg_attr(
-        not(all(target_os = "linux", any(feature = "wayland", feature = "x11"))),
+        not(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11"))),
         allow(dead_code)
     )]
     wake_sender: Sender<()>,
@@ -177,7 +177,7 @@ impl LinuxCommon {
 
     pub(crate) fn start_wake_listener(&mut self) {
         if !self.wake_listener_started {
-            #[cfg(all(target_os = "linux", any(feature = "wayland", feature = "x11")))]
+            #[cfg(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11")))]
             smol::spawn({
                 let wake_sender = self.wake_sender.clone();
                 async move {
@@ -200,7 +200,7 @@ impl LinuxCommon {
     }
 }
 
-#[cfg(all(target_os = "linux", any(feature = "wayland", feature = "x11")))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11")))]
 async fn listen_for_system_wake(wake_sender: Sender<()>) -> anyhow::Result<()> {
     use futures::StreamExt as _;
 
