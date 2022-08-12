--- src/platformsupport/devicediscovery/qdevicediscovery_udev.cpp.orig	2020-07-03 14:25:13 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_udev.cpp
@@ -46,11 +46,7 @@
 #include <QSocketNotifier>
 #include <QLoggingCategory>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
