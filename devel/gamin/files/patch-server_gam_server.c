--- server/gam_server.c.orig	Wed Aug 10 00:01:21 2005
+++ server/gam_server.c	Wed Aug 10 00:03:41 2005
@@ -170,9 +170,11 @@ gam_add_subscription(GamSubscription * s
 	if (gam_exclude_check (path)) 
 	{
 		GAM_DEBUG(DEBUG_INFO, "g_a_s: %s excluded\n", path);
+#ifdef ENABLE_INOTIFY
 		if (gam_inotify_is_running())
 			return gam_poll_add_subscription (sub);
 		else
+#endif
 			return gam_backend_add_subscription(sub);
 	} else {
 		gam_fs_mon_type type;
@@ -211,9 +213,11 @@ gam_remove_subscription(GamSubscription 
 
 	if (gam_exclude_check (path)) 
 	{
+#ifdef ENABLE_INOTIFY
 		if (gam_inotify_is_running())
 			return gam_poll_remove_subscription (sub);
 		else
+#endif
 			return gam_backend_remove_subscription(sub);
 	} else {
 		gam_fs_mon_type type;
@@ -300,15 +304,19 @@ gam_server_emit_one_event(const char *pa
 
     reqno = gam_subscription_get_reqno(sub);
 
+#ifdef ENABLE_INOTIFY
 	if (gam_inotify_is_running())
 	{
 		gam_queue_event(conn, reqno, event, subpath, len);
 	} else {
+#endif
 		if (gam_send_event(conn, reqno, event, subpath, len) < 0) {
 		GAM_DEBUG(DEBUG_INFO, "Failed to send event to PID %d\n",
 			  gam_connection_get_pid(conn));
 		}
+#ifdef ENABLE_INOTIFY
 	}
+#endif
 }
 
 /**
