--- src/daemon/daemon.c.orig	2007-05-26 09:52:28 UTC
+++ src/daemon/daemon.c
@@ -1091,10 +1091,6 @@ main(int argc, char **argv)
 	
 	g_set_application_name ("notification-daemon-xfce");
 
-#ifdef G_ENABLE_DEBUG
-	g_log_set_always_fatal(G_LOG_LEVEL_ERROR | G_LOG_LEVEL_CRITICAL);
-#endif
-
 	gtk_init(&argc, &argv);
 
 	error = NULL;
