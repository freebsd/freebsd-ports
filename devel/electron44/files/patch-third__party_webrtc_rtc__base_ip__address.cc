--- third_party/webrtc/rtc_base/ip_address.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/webrtc/rtc_base/ip_address.cc
@@ -22,7 +22,8 @@
 #include "rtc_base/string_utils.h"
 
 #if defined(WEBRTC_POSIX)
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #include <netdb.h>
