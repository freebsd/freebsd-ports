--- third_party/webrtc/rtc_base/ip_address.cc.orig	2022-05-11 07:17:59 UTC
+++ third_party/webrtc/rtc_base/ip_address.cc
@@ -11,7 +11,8 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
