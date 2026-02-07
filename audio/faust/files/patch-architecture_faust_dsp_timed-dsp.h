--- architecture/faust/dsp/timed-dsp.h.orig	2020-09-21 21:48:57 UTC
+++ architecture/faust/dsp/timed-dsp.h
@@ -47,7 +47,7 @@ namespace {
 #endif
 #endif
 
-#if __linux__
+#if __linux__ || defined(__FreeBSD__)
 #include <sys/time.h>
 inline double GetCurrentTimeInUsec() 
 {
