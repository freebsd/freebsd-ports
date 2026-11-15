--- third_party/crashpad/crashpad/snapshot/posix/timezone.cc.orig	2026-10-31 04:45:41 UTC
+++ third_party/crashpad/crashpad/snapshot/posix/timezone.cc
@@ -49,6 +49,10 @@ void TimeZone(const timeval& snapshot_time,
   // in the probes below. If tzname[1] is set to a bogus value, assume the
   // timezone does not actually use daylight saving time.
   if (daylight && strncmp(tzname[1], "_TZif", 5) != 0) {
+#elif BUILDFLAG(IS_BSD)
+  // BSD variants do not provide XSI `daylight` variable, so always rely on
+  // the probe to determine if DST is observed.
+  if (true) {
 #else
   if (daylight) {
 #endif
