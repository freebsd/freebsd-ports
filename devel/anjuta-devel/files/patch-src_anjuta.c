--- src/anjuta.c.orig	Sun Jun  8 23:31:48 2003
+++ src/anjuta.c	Sun Jun  8 23:33:26 2003
@@ -1938,6 +1938,8 @@
 	pid = waitpid (0, &status, WNOHANG);
 	if (pid < 1)
 		return;
+	if (!app)
+		return;
 	idx = g_list_index (app->registered_child_processes, (int *) pid);
 	if (idx < 0)
 		return;
