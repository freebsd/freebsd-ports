--- src/AudioIO.cpp.orig	2020-06-19 15:16:47 UTC
+++ src/AudioIO.cpp
@@ -490,7 +490,6 @@ time warp info and AudioIOListener and whether the pla
    #define ROUND(x) (int) ((x)+0.5)
    //#include <string.h>
 //   #include "../lib-src/portmidi/pm_common/portmidi.h"
-   #include "../lib-src/portaudio-v19/src/common/pa_util.h"
    #include "NoteTrack.h"
 #endif
 
@@ -814,13 +813,22 @@ struct AudioIoCallback::ScrubState (private)
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
