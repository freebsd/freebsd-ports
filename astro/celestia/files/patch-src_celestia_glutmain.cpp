$FreeBSD$

--- src/celestia/glutmain.cpp.orig	Sat Nov  2 23:20:19 2002
+++ src/celestia/glutmain.cpp	Tue Mar 16 12:47:46 2004
@@ -511,8 +511,8 @@
     // Set the simulation starting time to the current system time
     time_t curtime=time(NULL);
     appCore->start((double) curtime / 86400.0 + (double) astro::Date(1970, 1, 1));
-    #ifdef MACOSX
-    /* localtime in Darwin is is reentrant only
+    #if defined(MACOSX) || defined(__FreeBSD__)
+    /* localtime in Darwin is reentrant only
        equiv to Linux localtime_r()
        should probably port !MACOSX code to use this too, available since
        libc 5.2.5 according to manpage */
