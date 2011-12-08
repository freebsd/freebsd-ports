--- ./lib/c_glib/src/transport/thrift_socket.h.orig	2011-08-11 17:18:58.000000000 +0400
+++ ./lib/c_glib/src/transport/thrift_socket.h	2011-08-26 11:58:33.000000000 +0400
@@ -21,6 +21,8 @@
 #define _THRIFT_SOCKET_H
 
 #include <glib-object.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include "transport/thrift_transport.h"
 
