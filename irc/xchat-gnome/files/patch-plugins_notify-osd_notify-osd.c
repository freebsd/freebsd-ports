--- plugins/notify-osd/notify-osd.c.orig	2011-06-26 13:22:24.000000000 +0200
+++ plugins/notify-osd/notify-osd.c	2011-06-26 13:22:41.000000000 +0200
@@ -67,7 +67,7 @@
 	gchar *escaped;
 
 	escaped = g_markup_escape_text (message, strlen(message));
-	notify = notify_notification_new (summary, escaped, NULL, NULL);
+	notify = notify_notification_new (summary, escaped, NULL);
 	notify_notification_set_urgency (notify, NOTIFY_URGENCY_NORMAL);
 	notify_notification_set_icon_from_pixbuf (notify, notify_icon);
 	if (!notify_notification_show (notify, &error)) {
