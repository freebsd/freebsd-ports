--- lib/cpp/src/thrift/transport/SocketCommon.cpp.orig	2021-03-05 23:09:13 UTC
+++ lib/cpp/src/thrift/transport/SocketCommon.cpp
@@ -24,6 +24,11 @@
 
 #ifndef _WIN32
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
 #include <thrift/thrift-config.h>
 
 #ifdef HAVE_UNISTD_H
