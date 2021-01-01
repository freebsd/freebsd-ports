--- third_party/webrtc/rtc_base/network.h.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/network.h
@@ -24,6 +24,10 @@
 #include "rtc_base/networkmonitor.h"
 #include "rtc_base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
