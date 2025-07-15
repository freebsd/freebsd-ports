--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -21,6 +21,7 @@
 #endif
 #if defined(WEBRTC_POSIX) && !defined(__native_client__)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX) && !defined(__native_client__)
 
 namespace webrtc {
