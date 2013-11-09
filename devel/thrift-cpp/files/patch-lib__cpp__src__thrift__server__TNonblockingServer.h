--- ./lib/cpp/src/thrift/server/TNonblockingServer.h.orig	2013-08-15 18:04:29.000000000 +0400
+++ ./lib/cpp/src/thrift/server/TNonblockingServer.h	2013-10-16 01:15:53.000000000 +0400
@@ -38,7 +38,8 @@
 #include <unistd.h>
 #endif
 #include <event.h>
-
+#include <sys/types.h>
+#include <sys/socket.h>
 
 
 namespace apache { namespace thrift { namespace server {
