--- third_party/webrtc/rtc_base/byte_order.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/webrtc/rtc_base/byte_order.h
@@ -88,6 +88,8 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 
+#elif defined(WEBRTC_BSD)
+#include <sys/endian.h>
 #elif defined(WEBRTC_POSIX)
 #include <endian.h>
 #else
