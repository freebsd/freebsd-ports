--- src/settings/main.c.orig	2007-05-26 09:52:28 UTC
+++ src/settings/main.c
@@ -187,8 +187,7 @@ notification_settings_preview (GtkWidget
   /* create new preview notification */
   preview = notify_notification_new (_("Preview notification"),
     _("Lorem Ipsum is simply dummy text of the printing and typesetting industry."),
-      "notification-settings",
-      NULL);
+      "notification-settings");
 
   notify_notification_set_urgency (preview, NOTIFY_URGENCY_NORMAL);
   notify_notification_set_category(preview, "preview");
