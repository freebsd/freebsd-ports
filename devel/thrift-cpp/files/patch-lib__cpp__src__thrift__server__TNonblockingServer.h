--- lib/cpp/src/thrift/server/TNonblockingServer.h.orig	2021-02-04 23:07:31 UTC
+++ lib/cpp/src/thrift/server/TNonblockingServer.h
@@ -43,6 +43,9 @@
 #include <event2/event_compat.h>
 #include <event2/event_struct.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 namespace apache {
 namespace thrift {
 namespace server {
