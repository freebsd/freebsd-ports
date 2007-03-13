--- src/hardware/serialport/misc_util.h.orig
+++ src/hardware/serialport/misc_util.h
@@ -6,7 +6,7 @@
 #include "SDL_net.h"
 #include "support.h"
 
-#if defined LINUX || defined OS2
+#if defined LINUX || defined OS2 || defined FREEBSD
 #define NATIVESOCKETS
 
 #elif defined WIN32 
