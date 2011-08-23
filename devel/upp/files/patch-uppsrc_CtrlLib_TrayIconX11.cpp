--- uppsrc/CtrlLib/TrayIconX11.cpp.orig	2011-08-12 16:13:23.000000000 +0200
+++ uppsrc/CtrlLib/TrayIconX11.cpp	2011-08-12 16:14:01.000000000 +0200
@@ -106,7 +106,7 @@ void TrayIcon::Message(int type, const c
 	NotifyNotification *notification = notify_notification_new (title, text
 					, type == 1 ? "gtk-dialog-info"
 					: type == 2 ? "gtk-dialog-warning"
-					: "gtk-dialog-error", NULL);
+					: "gtk-dialog-error");
 	notify_notification_set_timeout(notification, timeout * 1000);
 	notify_notification_show (notification, &error);
 #endif
