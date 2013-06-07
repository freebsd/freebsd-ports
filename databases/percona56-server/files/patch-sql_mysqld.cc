--- sql/mysqld.cc.orig	2013-06-03 00:02:34.000000000 +0200
+++ sql/mysqld.cc	2013-06-06 00:57:21.510741832 +0200
@@ -6422,7 +6422,7 @@
 
 #ifdef HAVE_LIBWRAP
     {
-      if (mysql_socket_getfd(sock) == mysql_socket_getfd(ip_sock))
+      if (mysql_socket_getfd(sock) == mysql_socket_getfd(base_ip_sock))
       {
         struct request_info req;
         signal(SIGCHLD, SIG_DFL);
