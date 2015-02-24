--- tests/threaded.c.orig	2015-02-23 23:21:35.000000000 +0100
+++ tests/threaded.c	2015-02-23 23:22:06.000000000 +0100
@@ -92,6 +92,8 @@
   soup_server_add_handler (server, NULL, server_callback, NULL, NULL);
   g_thread_create ((GThreadFunc)soup_server_run, server, FALSE, NULL);
 
+  sleep(2);
+
   url = g_strdup_printf ("http://127.0.0.1:%d/", soup_server_get_port (server));
 
   for (i = 0; i < G_N_ELEMENTS (threads); i++) {
