--- src/speech.h.orig	2014-03-04 16:47:15 UTC
+++ src/speech.h
@@ -58,7 +58,7 @@
 
 // will look for espeak_data directory here, and also in user's home directory
 #ifndef PATH_ESPEAK_DATA
-   #define PATH_ESPEAK_DATA  "/usr/share/espeak-data"
+   #define PATH_ESPEAK_DATA  "%%DATADIR%%/espeak-data"
 #endif
 
 typedef unsigned short USHORT;
