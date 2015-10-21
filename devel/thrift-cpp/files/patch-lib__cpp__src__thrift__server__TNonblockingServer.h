--- lib/cpp/src/thrift/server/TNonblockingServer.h.orig	2015-10-13 19:19:36 UTC
+++ lib/cpp/src/thrift/server/TNonblockingServer.h
@@ -41,6 +41,9 @@
 #include <event2/event_compat.h>
 #include <event2/event_struct.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 namespace apache {
 namespace thrift {
 namespace server {
