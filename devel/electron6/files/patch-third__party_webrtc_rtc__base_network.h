--- third_party/webrtc/rtc_base/network.h.orig	2019-09-10 10:48:09 UTC
+++ third_party/webrtc/rtc_base/network.h
@@ -25,6 +25,10 @@
 #include "rtc_base/network_monitor.h"
 #include "rtc_base/third_party/sigslot/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
