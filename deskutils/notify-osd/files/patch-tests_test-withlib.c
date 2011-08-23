--- tests/test-withlib.c.orig	2011-08-16 13:52:38.000000000 +0200
+++ tests/test-withlib.c	2011-08-16 13:54:51.000000000 +0200
@@ -94,7 +94,7 @@ test_withlib_show_notification (void)
 
 	n = notify_notification_new ("Test",
 				     "You should see a normal notification",
-				     "", NULL);
+				     "");
 	notify_notification_show (n, NULL);
 	sleep (3);
 
@@ -109,7 +109,7 @@ test_withlib_update_notification (void)
 
 	n = notify_notification_new ("Test",
 				     "New notification",
-				     "", NULL);
+				     "");
 	res = notify_notification_show (n, NULL);
 	g_assert (res);
 	sleep (1);
@@ -135,7 +135,7 @@ test_withlib_pass_icon_data (void)
 
 	n = notify_notification_new ("Image Test",
 				     "You should see an image",
-				     "", NULL);
+				     "");
 	g_print ("iconpath: %s\n", SRCDIR"/icons/avatar.png");
 	pixbuf = gdk_pixbuf_new_from_file_at_scale (SRCDIR"/icons/avatar.png",
 						    64, 64, TRUE, NULL);
@@ -157,22 +157,22 @@ test_withlib_priority (void)
 
 	n1 = notify_notification_new ("Dummy Notification",
 				      "This is a test notification",
-				      "", NULL);
+				      "");
 	notify_notification_show (n1, NULL);
 	n2 = notify_notification_new ("Normal Notification",
 				      "You should see this *after* the urgent notification.",
-				      "", NULL);
+				      "");
 	notify_notification_set_urgency (n2, NOTIFY_URGENCY_LOW);
 	notify_notification_show (n2, NULL);
 	n3 = notify_notification_new ("Synchronous Notification",
 				      "You should immediately see this notification.",
-				      "", NULL);
+				      "");
 	notify_notification_set_hint_string (n3, "synchronous", "test");
 	notify_notification_set_urgency (n3, NOTIFY_URGENCY_NORMAL);
 	notify_notification_show (n3, NULL);
 	n4 = notify_notification_new ("Urgent Notification",
 				      "You should see a dialog box, and after, a normal notification.",
-				      "", NULL);
+				      "");
 	notify_notification_set_urgency (n4, NOTIFY_URGENCY_CRITICAL);
 	notify_notification_show (n4, NULL);
 	
@@ -207,7 +207,7 @@ test_withlib_actions (void)
 
 	n1 = notify_notification_new ("Notification with an action",
 				      "You should see that in a dialog box. Click the 'Action' button for the test to succeed.",
-				      "", NULL);
+				      "");
 	notify_notification_add_action (n1,
 					"action",
 					"Action",
@@ -231,7 +231,7 @@ test_withlib_close_notification (void)
 
 	n = notify_notification_new ("Test Title",
 				     "This notification will be closed prematurely...",
-				     "", NULL);
+				     "");
 	notify_notification_show (n, NULL);
 	
 	loop = g_main_loop_new(NULL, FALSE);
@@ -256,8 +256,7 @@ test_withlib_append_hint (void)
 	/* init notification, supply first line of body-text */
 	n = notify_notification_new ("Test (append-hint)",
 				     "The quick brown fox jumps over the lazy dog.",
-				     SRCDIR"/icons/avatar.png",
-				     NULL);
+				     SRCDIR"/icons/avatar.png");
 	res = notify_notification_show (n, NULL);
 	g_assert (res);
 	sleep (1);
@@ -296,8 +295,7 @@ test_withlib_icon_only_hint (void)
 	/* init notification, supply first line of body-text */
 	n = notify_notification_new (" ", /* needs this to be non-NULL */
 				     NULL,
-				     "notification-audio-play",
-				     NULL);
+				     "notification-audio-play");
 	notify_notification_set_hint_string (n, "icon-only", "allowed");
 	res = notify_notification_show (n, NULL);
 	g_assert (res);
@@ -314,8 +312,7 @@ test_withlib_swallow_markup (void)
 
 	n = notify_notification_new ("Swallow markup test",
 				     "This text is hopefully neither <b>bold</b>, <i>italic</i> nor <u>underlined</u>.\n\nA little math-notation:\n\n\ta &gt; b &lt; c = 0",
-				     SRCDIR"/icons/avatar.png",
-				     NULL);
+				     SRCDIR"/icons/avatar.png");
 	res = notify_notification_show (n, NULL);
 	g_assert (res);
 	sleep (2);
@@ -341,7 +338,7 @@ test_withlib_throttle (void)
 
 		// create dummy notification
 		snprintf (buf, 19, "Test #%.2d", i);
-		n = notify_notification_new (buf, buf, "", NULL);
+		n = notify_notification_new (buf, buf, "");
 
 		// inject it into the queue
 		res = notify_notification_show (n, &error);
