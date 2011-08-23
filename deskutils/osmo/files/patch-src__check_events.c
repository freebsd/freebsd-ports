--- src/check_events.c.orig	2011-08-12 15:17:59.000000000 +0200
+++ src/check_events.c	2011-08-12 15:20:36.000000000 +0200
@@ -454,9 +454,9 @@
 					a->date = 0;
 
 					if (textdesc != NULL)
-						a->notify = notify_notification_new (item->summary, textdesc, GTK_STOCK_DIALOG_WARNING, NULL);
+						a->notify = notify_notification_new (item->summary, textdesc, GTK_STOCK_DIALOG_WARNING);
 					else
-						a->notify = notify_notification_new (item->summary, text, GTK_STOCK_DIALOG_WARNING, NULL);
+						a->notify = notify_notification_new (item->summary, text, GTK_STOCK_DIALOG_WARNING);
 
 					g_free (textdesc);
 					g_free (text);
@@ -483,9 +483,7 @@
 #endif /* HAVE_LIBNOTIFY */
 
 					if (gtk_status_icon_get_visible (appGUI->osmo_trayicon)) {
-#ifdef HAVE_LIBNOTIFY
-						notify_notification_attach_to_status_icon (a->notify, appGUI->osmo_trayicon);
-#endif /* HAVE_LIBNOTIFY */
+
 				        gtk_status_icon_set_from_stock (appGUI->osmo_trayicon, OSMO_STOCK_SYSTRAY_TASK);
 
 						if (config.blink_on_events) {
@@ -532,9 +530,9 @@
 					a->time = -1;
 					a->date = 0;
 					if (textdesc != NULL)
-						a->notify = notify_notification_new (_("Alarm warning!"), textdesc, GTK_STOCK_DIALOG_INFO, NULL);
+						a->notify = notify_notification_new (_("Alarm warning!"), textdesc, GTK_STOCK_DIALOG_INFO);
 					else
-						a->notify = notify_notification_new (_("Alarm warning!"), text, GTK_STOCK_DIALOG_INFO, NULL);
+						a->notify = notify_notification_new (_("Alarm warning!"), text, GTK_STOCK_DIALOG_INFO);
 
 					notify_notification_set_timeout (a->notify, NOTIFY_EXPIRES_NEVER);
 					notify_notification_set_urgency (a->notify, NOTIFY_URGENCY_NORMAL);
@@ -545,9 +543,7 @@
 #endif /* HAVE_LIBNOTIFY */
 
 					if (gtk_status_icon_get_visible (appGUI->osmo_trayicon)) {
-#ifdef HAVE_LIBNOTIFY
-						notify_notification_attach_to_status_icon (a->notify, appGUI->osmo_trayicon);
-#endif /* HAVE_LIBNOTIFY */
+
 				        gtk_status_icon_set_from_stock (appGUI->osmo_trayicon, OSMO_STOCK_SYSTRAY_TASK);
 
 						if (config.blink_on_events) {
