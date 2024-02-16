Fix 'error: use of undeclared identifier'
https://github.com/HenrikBengtsson/parallelly/issues/112

--- src/test_tcp_port.c.orig	2024-02-02 01:02:32 UTC
+++ src/test_tcp_port.c
@@ -5,6 +5,7 @@
 #ifdef _WIN32
 #include <winsock2.h>
 #else
+#include <sys/socket.h>  /* socket(), listen(), bind(), AF_INET, ... */
 #include <netinet/in.h>
 #endif
 
