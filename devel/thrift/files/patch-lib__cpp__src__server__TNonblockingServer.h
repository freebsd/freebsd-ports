--- ./lib/cpp/src/server/TNonblockingServer.h.orig	2011-08-11 17:18:59.000000000 +0400
+++ ./lib/cpp/src/server/TNonblockingServer.h	2011-08-26 11:47:01.000000000 +0400
@@ -33,6 +33,9 @@
 #include <unistd.h>
 #include <event.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 namespace apache { namespace thrift { namespace server {
 
 using apache::thrift::transport::TMemoryBuffer;
