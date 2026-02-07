--- src/System/Link/socket_server.cpp.orig	2015-06-15 08:44:50 UTC
+++ src/System/Link/socket_server.cpp
@@ -21,6 +21,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/wait.h>
+#include <sys/time.h>
+#include <sys/select.h>
 #else
 namespace wsoc {
 #include <sys/types.h>
