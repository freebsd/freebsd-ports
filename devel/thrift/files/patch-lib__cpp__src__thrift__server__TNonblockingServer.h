--- ./lib/cpp/src/thrift/server/TNonblockingServer.h.orig	2012-10-12 04:58:06.000000000 +0400
+++ ./lib/cpp/src/thrift/server/TNonblockingServer.h	2012-10-16 16:42:27.884820801 +0400
@@ -38,7 +38,8 @@
 #include <unistd.h>
 #endif
 #include <event.h>
-
+#include <sys/types.h>
+#include <sys/socket.h>
 
 
 namespace apache { namespace thrift { namespace server {
