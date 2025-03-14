--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -343,7 +343,7 @@ base::TimeTicks EventMillisecondsToTimeTicks(uint32_t 
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
@@ -385,7 +385,7 @@ void RecordConnectionMetrics(wl_display* display) {
 }
 
 void RecordConnectionMetrics(wl_display* display) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   CHECK(display);
 
   // These values are logged to metrics so must not be changed.
