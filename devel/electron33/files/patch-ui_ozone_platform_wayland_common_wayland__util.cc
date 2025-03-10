--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2024-10-16 21:32:40 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -347,7 +347,7 @@ base::TimeTicks EventMillisecondsToTimeTicks(uint32_t 
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
@@ -389,7 +389,7 @@ void RecordConnectionMetrics(wl_display* display) {
 }
 
 void RecordConnectionMetrics(wl_display* display) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   CHECK(display);
 
   // These values are logged to metrics so must not be changed.
