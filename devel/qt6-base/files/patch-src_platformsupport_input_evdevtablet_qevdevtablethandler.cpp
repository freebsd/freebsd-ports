--- src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp.orig	2024-09-18 16:48:24 UTC
+++ src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp
@@ -10,9 +10,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 #include <qpa/qwindowsysteminterface.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
+#if defined(Q_OS_VXWORKS)
 #include <qpa/qplatformscreen.h>
 #include <evdevLib.h>
 #define SYN_REPORT      0
