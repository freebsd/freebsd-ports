--- src/speech.h	Tue Oct  3 00:51:13 2006
+++ src/speech.h.port	Wed Oct 11 23:43:20 2006
@@ -36,7 +36,7 @@
 #endif
 
 // will look for espeak_data directory here, and also in user's home directory
-#define PATH_ESPEAK_DATA  "/usr/share/espeak-data"
+#define PATH_ESPEAK_DATA  "%%DATADIR%%/espeak-data"
 
 typedef unsigned short USHORT;
 typedef unsigned char  UCHAR;
