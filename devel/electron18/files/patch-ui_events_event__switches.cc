--- ui/events/event_switches.cc.orig	2022-05-19 05:18:01 UTC
+++ ui/events/event_switches.cc
@@ -14,7 +14,7 @@ namespace switches {
 const char kCompensateForUnstablePinchZoom[] =
     "compensate-for-unstable-pinch-zoom";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
