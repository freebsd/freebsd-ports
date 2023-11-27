--- src/kj/cidr.c++.orig	2023-08-22 20:55:23 UTC
+++ src/kj/cidr.c++
@@ -39,6 +39,7 @@
 #else
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #endif
 
 namespace kj {
