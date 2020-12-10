- BSD macro (in sys/param.h) is an archaic of the (University of California) past

--- webrtc/base/stringutils.h.orig	2018-07-23 14:02:57 UTC
+++ webrtc/base/stringutils.h
@@ -23,7 +23,7 @@
 #endif  // WEBRTC_WIN 
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#ifdef WEBRTC_BSD
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
