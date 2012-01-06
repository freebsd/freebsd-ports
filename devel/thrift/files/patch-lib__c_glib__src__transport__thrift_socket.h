--- ./lib/c_glib/src/transport/thrift_socket.h.orig	2011-11-26 23:00:36.000000000 +0400
+++ ./lib/c_glib/src/transport/thrift_socket.h	2011-12-25 15:09:17.000000000 +0400
@@ -21,6 +21,8 @@
 #define _THRIFT_SOCKET_H
 
 #include <glib-object.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include "transport/thrift_transport.h"
 
