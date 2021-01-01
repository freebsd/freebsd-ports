--- chromecast/media/base/monotonic_clock.cc.orig	2019-12-12 12:39:27 UTC
+++ chromecast/media/base/monotonic_clock.cc
@@ -9,9 +9,9 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chromecast/media/base/buildflags.h"
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
 #include <zircon/syscalls.h>
@@ -20,7 +20,7 @@
 namespace chromecast {
 namespace media {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 int64_t MonotonicClockNow() {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
