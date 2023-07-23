--- third_party/capnproto/c++/src/kj/cidr.c++.orig	2023-07-23 06:08:18 UTC
+++ third_party/capnproto/c++/src/kj/cidr.c++
@@ -34,6 +34,8 @@
 #else
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #endif
 
 namespace kj {
