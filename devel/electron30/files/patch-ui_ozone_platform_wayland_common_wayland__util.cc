--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2024-04-15 20:34:30 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -337,7 +337,7 @@ base::TimeTicks EventMillisecondsToTimeTicks(uint32_t 
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1499638): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
