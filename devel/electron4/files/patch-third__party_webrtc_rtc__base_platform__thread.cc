--- third_party/webrtc/rtc_base/platform_thread.cc.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/platform_thread.cc
@@ -15,7 +15,9 @@
 #include "rtc_base/timeutils.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
