--- ui/events/event_switches.h.orig	2019-12-12 12:41:33 UTC
+++ ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
