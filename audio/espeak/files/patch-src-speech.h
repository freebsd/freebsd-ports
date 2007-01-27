--- src/speech.h	Fri Jan 26 10:11:59 2007
+++ src/speech.h.port	Sat Jan 27 00:46:28 2007
@@ -34,7 +34,7 @@
 
 // will look for espeak_data directory here, and also in user's home directory
 #ifndef PATH_ESPEAK_DATA
-   #define PATH_ESPEAK_DATA  "/usr/share/espeak-data"
+   #define PATH_ESPEAK_DATA  "%%DATADIR%%/espeak-data"
 #endif
 
 typedef unsigned short USHORT;
