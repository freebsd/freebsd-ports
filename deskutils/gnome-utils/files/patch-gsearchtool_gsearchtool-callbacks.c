--- gsearchtool/gsearchtool-callbacks.c.orig	Thu Dec 23 19:14:17 2004
+++ gsearchtool/gsearchtool-callbacks.c	Thu Dec 23 19:15:55 2004
@@ -54,9 +54,11 @@
 quit_application (GSearchCommandDetails * command_details)
 {
 	if (command_details->command_status == RUNNING) {
-		command_details->command_status = MAKE_IT_QUIT;
 #ifdef HAVE_GETPGID
 		pid_t pgid;
+#endif
+		command_details->command_status = MAKE_IT_QUIT;
+#ifdef HAVE_GETPGID
 		
 		pgid = getpgid (command_details->command_pid);
 		
@@ -122,10 +124,12 @@
 	GSearchWindow * gsearch = data;
 
 	if (gsearch->command_details->command_status == RUNNING) {
+#ifdef HAVE_GETPGID
+		pid_t pgid;
+#endif
 		gtk_widget_set_sensitive (gsearch->stop_button, FALSE);
 		gsearch->command_details->command_status = MAKE_IT_STOP;
 #ifdef HAVE_GETPGID
-		pid_t pgid;
 		
 		pgid = getpgid (gsearch->command_details->command_pid);
 		
