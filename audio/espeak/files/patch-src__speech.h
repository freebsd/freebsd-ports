--- ./src/speech.h.orig	2011-03-15 15:01:33.000000000 +0100
+++ ./src/speech.h	2011-03-18 10:12:28.000000000 +0100
@@ -57,7 +57,7 @@
 
 // will look for espeak_data directory here, and also in user's home directory
 #ifndef PATH_ESPEAK_DATA
-   #define PATH_ESPEAK_DATA  "/usr/share/espeak-data"
+   #define PATH_ESPEAK_DATA  "%%DATADIR%%/espeak-data"
 #endif
 
 typedef unsigned short USHORT;
