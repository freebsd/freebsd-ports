--- src/MIDIPlay.cpp.orig	2021-10-31 02:53:52 UTC
+++ src/MIDIPlay.cpp
@@ -490,7 +490,7 @@ static double SystemTime(bool usingAlsa)
    if (usingAlsa) {
       struct timespec now;
       // CLOCK_MONOTONIC_RAW is unaffected by NTP or adj-time
-      clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+      clock_gettime(CLOCK_REALTIME, &now);
       //return now.tv_sec + now.tv_nsec * 0.000000001;
       return (now.tv_sec + now.tv_nsec * 0.000000001) - streamStartTime;
    }
