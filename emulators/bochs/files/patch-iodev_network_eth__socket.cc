--- iodev/network/eth_socket.cc.orig	2017-11-15 14:29:17 UTC
+++ iodev/network/eth_socket.cc
@@ -78,16 +78,21 @@ extern "C" {
 #ifdef WIN32
 #include <winsock2.h>
 #else
+#include <sys/param.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
-#include <netpacket/packet.h>
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
