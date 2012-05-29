--- ./src/settings/main.c.orig	2012-05-29 15:07:41.000000000 +0200
+++ ./src/settings/main.c	2012-05-29 15:08:08.000000000 +0200
@@ -187,8 +187,7 @@
   /* create new preview notification */
   preview = notify_notification_new (_("Preview notification"),
     _("Lorem Ipsum is simply dummy text of the printing and typesetting industry."),
-      "notification-settings",
-      NULL);
+      "notification-settings");
 
   notify_notification_set_urgency (preview, NOTIFY_URGENCY_NORMAL);
   notify_notification_set_category(preview, "preview");
