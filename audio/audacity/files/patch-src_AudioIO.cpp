--- src/AudioIO.cpp.orig	2018-10-01 14:07:33 UTC
+++ src/AudioIO.cpp
@@ -480,7 +480,6 @@ TimeTrack and AudioIOListener and whether the playback
    #define ROUND(x) (int) ((x)+0.5)
    //#include <string.h>
 //   #include "../lib-src/portmidi/pm_common/portmidi.h"
-   #include "../lib-src/portaudio-v19/src/common/pa_util.h"
    #include "NoteTrack.h"
 #endif
 
@@ -793,13 +797,22 @@ struct AudioIO::ScrubState (private)
 // return the system time as a double
 static double streamStartTime = 0; // bias system time to small number
 
+// PaUtil_GetTime is an internal PortAudio function.  Unfortunately
+// it's used twice in AudioIO.cpp.  It's a simple function so just
+// provide the implementation here.
+static double PaUtil_GetTime(void) {
+   struct timespec tp;
+   clock_gettime(CLOCK_REALTIME, &tp);
+   return (double)(tp.tv_sec + tp.tv_nsec * 1e-9);
+}
+
 static double SystemTime(bool usingAlsa)
 {
 #ifdef __WXGTK__
    if (usingAlsa) {
       struct timespec now;
       // CLOCK_MONOTONIC_RAW is unaffected by NTP or adj-time
-      clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+      clock_gettime(CLOCK_REALTIME, &now);
       //return now.tv_sec + now.tv_nsec * 0.000000001;
       return (now.tv_sec + now.tv_nsec * 0.000000001) - streamStartTime;
    }
