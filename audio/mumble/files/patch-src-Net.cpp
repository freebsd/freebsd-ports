--- src/Net.cpp.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/Net.cpp	2010-01-10 23:55:48.000000000 +0200
@@ -29,6 +29,12 @@
 */
 
 #include "Net.h"
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
+#endif
 
 HostAddress::HostAddress() {
 	addr[0] = addr[1] = 0ULL;
