--- src/network/stk_ipv6.cpp.orig	2020-01-03 18:47:06 UTC
+++ src/network/stk_ipv6.cpp
@@ -39,6 +39,7 @@ extern "C"
 #else
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <err.h>
 #include <netdb.h>
 #include <sys/socket.h>
