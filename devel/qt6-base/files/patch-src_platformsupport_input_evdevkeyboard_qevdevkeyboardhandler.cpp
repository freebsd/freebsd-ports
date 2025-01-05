--- src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp.orig	2024-09-18 16:48:24 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp
@@ -17,9 +17,7 @@
 #include <QtGui/private/qguiapplication_p.h>
 #include <QtGui/private/qinputdevicemanager_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
+#if defined(Q_OS_VXWORKS)
 #include <evdevLib.h>
 #else
 #include <linux/input.h>
