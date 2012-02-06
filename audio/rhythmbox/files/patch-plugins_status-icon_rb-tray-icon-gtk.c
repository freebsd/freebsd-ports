--- plugins/status-icon/rb-tray-icon-gtk.c.orig	2012-02-05 23:21:11.000000000 -0500
+++ plugins/status-icon/rb-tray-icon-gtk.c	2012-02-05 23:21:24.000000000 -0500
@@ -339,14 +339,6 @@ rb_tray_icon_is_embedded (RBTrayIcon *tr
 	return gtk_status_icon_is_embedded (tray->priv->icon);
 }
 
-#if defined(HAVE_NOTIFY)
-void
-rb_tray_icon_attach_notification (RBTrayIcon *tray, NotifyNotification *notification)
-{
-	notify_notification_attach_to_status_icon (notification, tray->priv->icon);
-}
-#endif
-
 void
 rb_tray_icon_set_visible (RBTrayIcon *tray, gboolean visible)
 {
