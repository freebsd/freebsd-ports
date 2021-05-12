--- base/process/process_unittest.cc.orig	2021-04-14 01:08:36 UTC
+++ base/process/process_unittest.cc
@@ -138,7 +138,7 @@ TEST_F(ProcessTest, CreationTimeOtherProcess) {
   // was spawned and a time recorded after it was spawned. However, since the
   // base::Time and process creation clocks don't match, tolerate some error.
   constexpr base::TimeDelta kTolerance =
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // On Linux, process creation time is relative to boot time which has a
       // 1-second resolution. Tolerate 1 second for the imprecise boot time and
       // 100 ms for the imprecise clock.
