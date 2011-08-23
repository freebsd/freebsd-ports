--- plugins/status-icon/rb-status-icon-plugin.c.orig	2011-08-21 21:46:27.000000000 +0200
+++ plugins/status-icon/rb-status-icon-plugin.c	2011-08-21 21:46:43.000000000 +0200
@@ -394,7 +394,7 @@ do_notify (RBStatusIconPlugin *plugin,
 		icon_name = NULL;
 
 	if (plugin->priv->notification == NULL) {
-		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name, NULL);
+		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name);
 
 		g_signal_connect_object (plugin->priv->notification,
 					 "closed",
