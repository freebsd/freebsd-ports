--- src/platformsupport/devicediscovery/qdevicediscovery_udev.cpp.orig	2022-09-19 10:23:04 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_udev.cpp
@@ -10,11 +10,7 @@
 #include <QSocketNotifier>
 #include <QLoggingCategory>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
