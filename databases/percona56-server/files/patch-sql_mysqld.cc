--- sql/mysqld.cc.orig	2013-03-05 00:04:54.000000000 +0100
+++ sql/mysqld.cc	2013-03-18 09:55:35.499120018 +0100
@@ -6291,7 +6291,7 @@
 
 #ifdef HAVE_LIBWRAP
     {
-      if (mysql_socket_getfd(sock) == mysql_socket_getfd(ip_sock))
+      if (mysql_socket_getfd(sock) == mysql_socket_getfd(base_ip_sock))
       {
         struct request_info req;
         signal(SIGCHLD, SIG_DFL);
@@ -6323,7 +6323,7 @@
             The connection was refused by TCP wrappers.
             There are no details (by client IP) available to update the host_cache.
           */
-          statistic_increment(connection_tcpwrap_errors, &LOCK_status);
+          statistic_increment(connection_errors_tcpwrap, &LOCK_status);
           continue;
         }
       }
