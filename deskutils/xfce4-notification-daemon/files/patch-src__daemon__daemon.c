--- ./src/daemon/daemon.c.orig	2010-05-05 10:54:14.000000000 +0200
+++ ./src/daemon/daemon.c	2010-05-05 10:54:50.000000000 +0200
@@ -1091,10 +1091,6 @@
 	
 	g_set_application_name ("notification-daemon-xfce");
 
-#ifdef G_ENABLE_DEBUG
-	g_log_set_always_fatal(G_LOG_LEVEL_ERROR | G_LOG_LEVEL_CRITICAL);
-#endif
-
 	gtk_init(&argc, &argv);
 
 	error = NULL;
