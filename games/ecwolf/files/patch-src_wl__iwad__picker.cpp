--- src/wl_iwad_picker.cpp.orig	2023-01-18 23:02:12 UTC
+++ src/wl_iwad_picker.cpp
@@ -27,6 +27,8 @@ void TXT_PickWad(TXT_UNCAST_ARG(widget), int wad)
 int I_PickIWad_Cocoa (WadStuff *wads, int numwads, bool showwin, int defaultiwad);
 #elif defined(__ANDROID__)
 int I_PickIWad_Android (WadStuff *wads, int numwads, bool showwin, int defaultiwad);
+#elif defined(__FreeBSD__)
+#include <sys/wait.h>
 #endif
 
 #ifndef NO_GTK
