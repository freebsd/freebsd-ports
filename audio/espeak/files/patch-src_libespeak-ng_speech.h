--- src/libespeak-ng/speech.h.orig	2022-06-21 14:53:53 UTC
+++ src/libespeak-ng/speech.h
@@ -56,7 +56,7 @@ extern "C"
 
 // will look for espeak_data directory here, and also in user's home directory
 #ifndef PATH_ESPEAK_DATA
-   #define PATH_ESPEAK_DATA  "/usr/share/espeak-ng-data"
+   #define PATH_ESPEAK_DATA  "%%DATADIR%%/espeak-ng-data"
 #endif
 
 void cancel_audio(void);
