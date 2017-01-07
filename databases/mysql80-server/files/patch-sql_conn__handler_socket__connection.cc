--- sql/conn_handler/socket_connection.cc.orig	2016-03-28 18:06:12 UTC
+++ sql/conn_handler/socket_connection.cc
@@ -939,20 +939,23 @@ Channel_info* Mysqld_socket_listener::li
     signal(SIGCHLD, SIG_DFL);
     request_init(&req, RQ_DAEMON, m_libwrap_name, RQ_FILE,
                  mysql_socket_getfd(connect_sock), NULL);
-    fromhost(&req);
+    void (*my_fromhost) (void *) = (void (*)(void *)) fromhost;
+    my_fromhost(&req);
 
-    if (!hosts_access(&req))
+    int (*my_hosts_access) (void *) = (int (*) (void *)) hosts_access;
+    if (!my_hosts_access(&req))
     {
       /*
         This may be stupid but refuse() includes an exit(0)
         which we surely don't want...
         clean_exit() - same stupid thing ...
       */
+      char *(*my_eval_client) (void *) = (char *(*) (void *)) eval_client;
       syslog(LOG_AUTH | m_deny_severity,
-             "refused connect from %s", eval_client(&req));
+             "refused connect from %s", my_eval_client(&req));
 
       if (req.sink)
-        (req.sink)(req.fd);
+        ((void (*)(int)) (req.sink))(req.fd);
 
       mysql_socket_shutdown(listen_sock, SHUT_RDWR);
       mysql_socket_close(listen_sock);
