--- src/systray.c.orig	2011-08-16 13:49:31.000000000 +0200
+++ src/systray.c	2011-08-16 13:49:44.000000000 +0200
@@ -224,7 +224,7 @@ gwget_tray_notify (gchar *primary, gchar
        		if (!notify_is_initted ())
 			if (!notify_init ("gwget"))
 		               return;
-       NotifyNotification *notification = notify_notification_new(primary,secondary,icon_name,NULL);
+       NotifyNotification *notification = notify_notification_new(primary,secondary,icon_name);
        notify_notification_show(notification,NULL);
 #endif
 
