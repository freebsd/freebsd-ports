--- iodev/network/eth_socket.cc.orig	2019-12-09 16:29:23 UTC
+++ iodev/network/eth_socket.cc
@@ -95,7 +95,12 @@ extern "C" {
 #include <netinet/in.h>
 #include <net/ethernet.h>
 #include <net/if.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#else
+#include <netpacket/packet.h>
 #include <linux/types.h>
+#endif
 #include <netdb.h>
 #define closesocket(s) close(s)
 typedef int SOCKET;
