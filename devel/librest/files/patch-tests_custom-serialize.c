--- tests/custom-serialize.c.orig	2015-02-23 23:22:16.000000000 +0100
+++ tests/custom-serialize.c	2015-02-23 23:22:28.000000000 +0100
@@ -125,6 +125,8 @@
   soup_server_add_handler (server, NULL, server_callback, NULL, NULL);
   g_thread_create ((GThreadFunc)soup_server_run, server, FALSE, NULL);
 
+  sleep(2);
+
   url = g_strdup_printf ("http://127.0.0.1:%d/", soup_server_get_port (server));
 
   proxy = rest_proxy_new (url, FALSE);
