--- plugins/status-icon/rb-status-icon-plugin.c.orig	2010-03-24 20:10:13.000000000 -0400
+++ plugins/status-icon/rb-status-icon-plugin.c	2012-02-05 23:19:58.000000000 -0500
@@ -394,7 +394,7 @@ do_notify (RBStatusIconPlugin *plugin,
 		icon_name = NULL;
 
 	if (plugin->priv->notification == NULL) {
-		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name, NULL);
+		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name);
 
 		g_signal_connect_object (plugin->priv->notification,
 					 "closed",
@@ -405,21 +405,6 @@ do_notify (RBStatusIconPlugin *plugin,
 		notify_notification_update (plugin->priv->notification, primary, secondary, icon_name);
 	}
 
-	switch (plugin->priv->icon_mode) {
-	case ICON_NEVER:
-		break;
-
-	case ICON_WITH_NOTIFY:
-	case ICON_ALWAYS:
-	case ICON_OWNS_WINDOW:
-		rb_tray_icon_attach_notification (plugin->priv->tray_icon,
-						  plugin->priv->notification);
-		break;
-
-	default:
-		g_assert_not_reached ();
-	}
-
 	notify_notification_set_timeout (plugin->priv->notification, timeout);
 
 	if (pixbuf != NULL) {
