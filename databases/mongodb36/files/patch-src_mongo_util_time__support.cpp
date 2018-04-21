--- src/mongo/util/time_support.cpp.orig	2018-04-19 11:21:07 UTC
+++ src/mongo/util/time_support.cpp
@@ -933,7 +933,7 @@ private:
 // Find minimum timer resolution of OS
 Nanoseconds getMinimumTimerResolution() {
     Nanoseconds minTimerResolution;
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     struct timespec tp;
     clock_getres(CLOCK_REALTIME, &tp);
     minTimerResolution = Nanoseconds{tp.tv_nsec};
