--- ui/events/event_switches.h.orig	2020-05-26 07:49:14 UTC
+++ ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
