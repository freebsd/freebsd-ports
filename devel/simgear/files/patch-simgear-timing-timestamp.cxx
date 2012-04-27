--- simgear/timing/timestamp.cxx.orig	2012-03-09 10:37:52.770699568 +0100
+++ simgear/timing/timestamp.cxx	2012-03-09 10:38:40.266717310 +0100
@@ -139,7 +139,7 @@
 // the timer tick) accuracy which is too bad to catch 60Hz...
 bool SGTimeStamp::sleepUntil(const SGTimeStamp& abstime)
 {
-#if defined(_POSIX_TIMERS) && (0 < _POSIX_TIMERS)
+#if defined(_POSIX_TIMERS) && (0 < _POSIX_TIMERS) && !defined(__FreeBSD__)
     SGTimeStamp abstimeForSleep = abstime;
 
     // Always undersleep by resolution of the clock
@@ -234,7 +234,7 @@
 
 bool SGTimeStamp::sleepFor(const SGTimeStamp& reltime)
 {
-#if defined(_POSIX_TIMERS) && (0 < _POSIX_TIMERS)
+#if defined(_POSIX_TIMERS) && (0 < _POSIX_TIMERS) && !defined(__FreeBSD__)
     struct timespec ts;
     ts.tv_sec = reltime._sec;
     ts.tv_nsec = reltime._nsec;
