--- base/include/preferences.h.orig	Wed Jan  1 08:33:21 2003
+++ base/include/preferences.h	Sat Jan 18 04:26:42 2003
@@ -28,6 +28,8 @@
 #include "config.h"
 #include "errors.h"
 
+using namespace std;
+
 // preferences
 ZINF_EXPORT extern const char* kInstallDirPref;
 ZINF_EXPORT extern const char* kLibraryPathPref;
