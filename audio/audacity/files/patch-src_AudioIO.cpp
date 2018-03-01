--- src/AudioIO.cpp.orig	2018-02-22 14:12:03.835431000 -0800
+++ src/AudioIO.cpp	2018-02-22 14:01:49.487127000 -0800
@@ -985,7 +985,7 @@
    if (usingAlsa) {
       struct timespec now;
       // CLOCK_MONOTONIC_RAW is unaffected by NTP or adj-time
-      clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+      clock_gettime(CLOCK_REALTIME, &now);
       //return now.tv_sec + now.tv_nsec * 0.000000001;
       return (now.tv_sec + now.tv_nsec * 0.000000001) - streamStartTime;
    }
