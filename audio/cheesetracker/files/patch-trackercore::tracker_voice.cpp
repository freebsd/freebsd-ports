--- trackercore/tracker_voice.cpp.orig	Sun Oct 26 05:00:37 2003
+++ trackercore/tracker_voice.cpp	Thu Oct 30 12:02:37 2003
@@ -16,6 +16,11 @@
 
 #include "tracker_voice.h"
 
+#if defined(__FreeBSD__)
+  #define lrint(flt)	((int) (flt))
+  #define lrintf(flt)	((int) (flt))
+#endif
+
 
 int Tracker_Voice::get_current_freq() {
 
