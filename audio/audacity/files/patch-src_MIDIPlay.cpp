--- src/MIDIPlay.cpp.orig	2022-09-27 05:35:02 UTC
+++ src/MIDIPlay.cpp
@@ -490,7 +490,7 @@ static double SystemTime(bool usingAlsa)
    if (usingAlsa) {
       struct timespec now;
       // CLOCK_MONOTONIC_RAW is unaffected by NTP or adj-time
-#ifdef FreeBSD
+#ifdef __FreeBSD__
       clock_gettime(CLOCK_REALTIME, &now);
 #else
       clock_gettime(CLOCK_MONOTONIC_RAW, &now);
