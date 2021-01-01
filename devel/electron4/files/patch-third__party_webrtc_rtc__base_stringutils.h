--- third_party/webrtc/rtc_base/stringutils.h.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/stringutils.h
@@ -24,11 +24,11 @@
 #endif  // WEBRTC_WIN
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#if defined(WEBRTC_BSD) || defined(BSD)
 #include <stdlib.h>
-#else  // BSD
+#else  // WEBRTC_BSD
 #include <alloca.h>
-#endif  // !BSD
+#endif  // !WEBRTC_BSD
 #endif  // WEBRTC_POSIX
 
 #include <string>
