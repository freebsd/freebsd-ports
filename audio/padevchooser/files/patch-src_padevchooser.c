--- src/padevchooser.c.orig	2011-08-11 21:41:17.000000000 +0200
+++ src/padevchooser.c	2011-08-11 21:41:42.000000000 +0200
@@ -162,7 +162,7 @@ static void notify_event(const char *tit
         
     if (!notification) {
         s = g_strdup_printf("<i>%s</i>\n%s", title, text);
-        notification = notify_notification_new(title, s, "audio-card", GTK_WIDGET(tray_icon));
+        notification = notify_notification_new(title, s, "audio-card");
         notify_notification_set_category(notification, "device.added");
         notify_notification_set_urgency(notification, NOTIFY_URGENCY_LOW);
         g_signal_connect_swapped(G_OBJECT(notification), "closed", G_CALLBACK(notification_closed), NULL);
