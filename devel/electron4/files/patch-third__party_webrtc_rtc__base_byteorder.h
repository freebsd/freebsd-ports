--- third_party/webrtc/rtc_base/byteorder.h.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/byteorder.h
@@ -79,7 +79,7 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 namespace rtc {
