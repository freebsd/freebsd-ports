--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2024-09-18 16:48:24 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -19,9 +19,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
+#if defined(Q_OS_VXWORKS)
 #include <qpa/qplatformscreen.h>
 #include <evdevLib.h>
 #define SYN_REPORT      0
