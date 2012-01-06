--- ./lib/cpp/src/server/TNonblockingServer.h.orig	2011-11-26 23:00:40.000000000 +0400
+++ ./lib/cpp/src/server/TNonblockingServer.h	2011-12-25 15:09:17.000000000 +0400
@@ -35,6 +35,9 @@
 #endif
 #include <event.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 namespace apache { namespace thrift { namespace server {
 
 using apache::thrift::transport::TMemoryBuffer;
