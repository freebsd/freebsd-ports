--- src/main.c.orig	2011-08-15 20:09:01.000000000 +0200
+++ src/main.c	2011-08-15 20:09:22.000000000 +0200
@@ -698,7 +698,7 @@ system_notify (GooWindow  *window,
 	}
 
 	if (notification == NULL) {
-		notification = notify_notification_new (title, msg, "goobox", NULL);
+		notification = notify_notification_new (title, msg, "goobox");
 		notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 		notify_notification_add_action (notification,
 						GTK_STOCK_MEDIA_NEXT,
