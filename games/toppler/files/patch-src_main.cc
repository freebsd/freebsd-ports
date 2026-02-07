--- src/main.cc.orig	2022-02-06 08:35:59 UTC
+++ src/main.cc
@@ -33,6 +33,8 @@
 #include <dirent.h>
 #endif
 
+#include <time.h>
+
 static void printhelp(void) {
   printf(_("\n\tOptions:\n\n  -f\tEnable fullscreen mode\n  -s\tSilence, disable all sound\n  -dX\tSet debug level to X  (default: %i)\n").c_str(), config.debug_level());
 }
