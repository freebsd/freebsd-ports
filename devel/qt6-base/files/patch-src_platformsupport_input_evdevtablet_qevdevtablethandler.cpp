--- src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp.orig	2025-02-19 13:05:34 UTC
+++ src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp
@@ -10,11 +10,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 #include <qpa/qwindowsysteminterface.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
