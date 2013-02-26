--- ./lib/c_glib/src/thrift/transport/thrift_socket.h.orig	2012-10-12 04:58:04.000000000 +0400
+++ ./lib/c_glib/src/thrift/transport/thrift_socket.h	2012-10-16 16:39:22.000000000 +0400
@@ -21,6 +21,8 @@
 #define _THRIFT_SOCKET_H
 
 #include <glib-object.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include <thrift/transport/thrift_transport.h>
 
