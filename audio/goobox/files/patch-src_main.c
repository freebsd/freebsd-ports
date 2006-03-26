--- src/main.c.orig	Fri Nov 18 21:20:08 2005
+++ src/main.c	Mon Feb 20 22:41:55 2006
@@ -47,7 +47,6 @@
 
 #ifdef HAVE_LIBNOTIFY
 #include <libnotify/notify.h>
-static NotifyHandle *notify_h = NULL;
 #endif /* HAVE_LIBNOTIFY */
 
 GtkWindow *main_window = NULL;
@@ -193,7 +192,7 @@
 
 #ifdef HAVE_LIBNOTIFY
 	if (! notify_init ("goobox")) 
-                g_error ("Cannot initialize notification system.");
+                g_warning ("Cannot initialize notification system.");
 #endif /* HAVE_LIBNOTIFY */
 
 	goo_stock_init ();
@@ -557,27 +556,10 @@
 	       int         y)
 {
 #ifdef HAVE_LIBNOTIFY
-	NotifyIcon  *icon = notify_icon_new_from_uri("goobox");
-	NotifyHints *hints = NULL;
-
-	if ((x >= 0) && (y >= 0)) {
-		hints = notify_hints_new ();
-		notify_hints_set_int (hints, "x", x);
-		notify_hints_set_int (hints, "y", y);
-	}
+	if(!notify_is_initted())
+		return;
+	NotifyNotification *n = notify_notification_new (title,msg,"goobox",GTK_WIDGET (main_window));
+	notify_notification_show(n, NULL);
 
-	notify_h = notify_send_notification (notify_h,
-					     "device",
-					     NOTIFY_URGENCY_NORMAL,
-					     title,
-					     msg,
-					     icon,
-					     TRUE, 0, 
-					     hints, // no hints
-					     NULL, // no user data
-					     0);
-	
-	if (icon != NULL)
-		notify_icon_destroy (icon);
 #endif /* HAVE_LIBNOTIFY */
 }
