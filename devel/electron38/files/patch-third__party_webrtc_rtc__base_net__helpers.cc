--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
