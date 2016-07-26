--- src/Net.cpp.orig	2014-08-08 15:51:59 UTC
+++ src/Net.cpp
@@ -31,6 +31,12 @@
 #include "murmur_pch.h"
 
 #include "Net.h"
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
+#endif
 
 HostAddress::HostAddress() {
 	addr[0] = addr[1] = 0ULL;
