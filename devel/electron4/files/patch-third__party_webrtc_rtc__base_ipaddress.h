--- third_party/webrtc/rtc_base/ipaddress.h.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/ipaddress.h
@@ -17,6 +17,10 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #if defined(WEBRTC_WIN)
 #include <winsock2.h>
 #include <ws2tcpip.h>
