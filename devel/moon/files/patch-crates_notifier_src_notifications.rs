--- crates/notifier/src/notifications.rs.orig	2026-06-29 20:41:23 UTC
+++ crates/notifier/src/notifications.rs
@@ -31,7 +31,7 @@ fn configure_application(_notification: &mut Notificat
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(all(unix, not(target_os = "macos")))]
 fn configure_application(_notification: &mut Notification) {}
 
 #[cfg(windows)]
