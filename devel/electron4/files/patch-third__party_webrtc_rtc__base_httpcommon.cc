--- third_party/webrtc/rtc_base/httpcommon.cc.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/rtc_base/httpcommon.cc
@@ -459,7 +459,7 @@ bool HttpDateToSeconds(const std::string& date, time_t
   }
 // TODO: Android should support timezone, see b/2441195
 #if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || \
-    defined(BSD)
+    defined(WEBRTC_BSD)
   tm* tm_for_timezone = localtime(&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
