--- sql/conn_handler/socket_connection.cc.orig	2023-06-21 07:52:10 UTC
+++ sql/conn_handler/socket_connection.cc
@@ -960,9 +960,11 @@ bool check_connection_refused_by_tcp_wrapper(MYSQL_SOC
   signal(SIGCHLD, SIG_DFL);
   request_init(&req, RQ_DAEMON, libwrap_name, RQ_FILE,
                mysql_socket_getfd(connect_sock), NULL);
-  fromhost(&req);
+  void (*my_fromhost) (void *) = (void (*)(void *)) fromhost;
+  my_fromhost(&req);
 
-  if (!hosts_access(&req)) {
+  int (*my_hosts_access) (void *) = (int (*) (void *)) hosts_access;
+  if (!my_hosts_access(&req)) {
     /*
       This may be stupid but refuse() includes an exit(0)
       which we surely don't want...
@@ -974,12 +976,13 @@ bool check_connection_refused_by_tcp_wrapper(MYSQL_SOC
       This is unproblematic as TCP-wrapper is unix specific,
       anyway.
     */
+    char *(*my_eval_client) (void *) = (char *(*) (void *)) eval_client;
     syslog(LOG_AUTH | LOG_WARNING, "refused connect from %s",
-           eval_client(&req));
+           my_eval_client(&req));
 
 #ifdef HAVE_LIBWRAP_PROTOTYPES
     // Some distros have patched tcpd.h to have proper prototypes
-    if (req.sink) (req.sink)(req.fd);
+    if (req.sink) ((void (*)(int)) (req.sink))(req.fd);
 #else
     // Some distros have not patched tcpd.h
     if (req.sink) ((void (*)(int))req.sink)(req.fd);
