$FreeBSD$

--- src/celestia/glutmain.cpp.orig	Tue Apr 30 10:36:11 2002
+++ src/celestia/glutmain.cpp	Sat May 18 16:16:21 2002
@@ -509,7 +509,7 @@
     // Set the simulation starting time to the current system time
     time_t curtime=time(NULL);
     appCore->start((double) curtime / 86400.0 + (double) astro::Date(1970, 1, 1));
-    #ifdef MACOSX
+    #if defined(MACOSX) || defined(__FreeBSD__)
     /* localtime in Darwin is is reentrant only
        equiv to Linux localtime_r()
        should probably port !MACOSX code to use this too, available since
