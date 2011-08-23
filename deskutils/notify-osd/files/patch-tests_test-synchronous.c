--- tests/test-synchronous.c.orig	2011-08-16 13:55:36.000000000 +0200
+++ tests/test-synchronous.c	2011-08-16 13:56:05.000000000 +0200
@@ -38,7 +38,7 @@ send_normal (const gchar *message)
         NotifyNotification *n;
 	n = notify_notification_new ("Test notification",
 				     g_strdup (message),
-				     "", NULL);
+				     "");
 	notify_notification_show (n, NULL);
 	g_object_unref(G_OBJECT(n));
 }
@@ -53,8 +53,7 @@ send_synchronous (const char *type,
 	if (n == NULL)
 		n = notify_notification_new (" ",
 					     "",
-					     g_strdup (icon),
-					     NULL);
+					     g_strdup (icon));
 	else
 		notify_notification_update (n,
 					    " ",
