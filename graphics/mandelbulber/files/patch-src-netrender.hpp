--- src/netrender.hpp.orig	2012-12-02 20:22:54.000000000 +0400
+++ src/netrender.hpp	2012-12-13 01:05:50.537932343 +0400
@@ -19,6 +19,7 @@
 	#include <winsock2.h>
 	#define INET6_ADDRSTRLEN 46
 #else
+	#include <arpa/inet.h>
 	#include <sys/socket.h>
 	#include <netdb.h>
 #endif
