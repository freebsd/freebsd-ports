--- xs/Notify.xs.orig	2007-10-04 07:11:13.000000000 -0500
+++ xs/Notify.xs	2012-04-29 05:18:14.725067334 -0500
@@ -86,26 +86,12 @@ notify_get_server_info (class, OUTLIST c
 MODULE = Gtk2::Notify	PACKAGE = Gtk2::Notify	PREFIX = notify_notification_
 
 NotifyNotification *
-notify_notification_new (class, summary, body=NULL, icon=NULL, attach=NULL)
+notify_notification_new (class, summary, body=NULL, icon=NULL)
 		const gchar *summary
 		const gchar *body
 		const gchar *icon
-		GtkWidget_ornull *attach
 	C_ARGS:
-		summary, body, icon, attach
-
-#if GTK_CHECK_VERSION (2, 9, 2)
-
-NotifyNotification *
-notify_notification_new_with_status_icon (class, summary, body=NULL, icon=NULL, status_icon=NULL)
-		const gchar *summary
-		const gchar *body
-		const gchar *icon
-		GtkStatusIcon *status_icon
-	C_ARGS:
-		summary, body, icon, status_icon
-
-#endif
+		summary, body, icon
 
 gboolean
 notify_notification_update (notification, summary, message=NULL, icon=NULL)
@@ -114,27 +100,6 @@ notify_notification_update (notification
 		const gchar *message
 		const gchar *icon
 
-void
-notify_notification_attach_to_widget (notification, attach)
-		NotifyNotification *notification
-		GtkWidget *attach
-
-#if GTK_CHECK_VERSION (2, 9, 2)
-
-void
-notify_notification_attach_to_status_icon (notification, status_icon)
-		NotifyNotification *notification
-		GtkStatusIcon *status_icon
-
-#endif
-
-void
-notify_notification_set_geometry_hints (notification, screen, x, y)
-		NotifyNotification *notification
-		GdkScreen *screen
-		gint x
-		gint y
-
 NO_OUTPUT gboolean
 notify_notification_show (notification)
 		NotifyNotification *notification
@@ -168,6 +133,11 @@ notify_notification_set_icon_from_pixbuf
 		GdkPixbuf *icon
 
 void
+notify_notification_set_image_from_pixbuf (notification, pixbuf)
+		NotifyNotification *notification
+		GdkPixbuf *pixbuf
+
+void
 set_hint (notification, key, value)
 		NotifyNotification *notification
 		const gchar *key
@@ -197,6 +167,12 @@ notify_notification_set_hint_int32 (noti
 		gint value
 
 void
+notify_notification_set_hint_uint32 (notification, key, value)
+		NotifyNotification *notification
+		const gchar *key
+		guint value
+
+void
 notify_notification_set_hint_double (notification, key, value)
 		NotifyNotification *notification
 		const gchar *key
