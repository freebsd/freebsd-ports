--- lib/cpp/src/thrift/transport/SocketCommon.cpp.orig	2022-01-20 19:36:56 UTC
+++ lib/cpp/src/thrift/transport/SocketCommon.cpp
@@ -26,6 +26,11 @@
 
 #include <cstring>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
 namespace apache {
 namespace thrift {
 namespace transport {
