--- src/platformsupport/devicediscovery/qdevicediscovery_static.cpp.orig	2024-09-18 16:48:24 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_static.cpp
@@ -11,9 +11,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
+#if defined(Q_OS_VXWORKS)
 #include <evdevLib.h>
 #define ABS_X           EV_DEV_PTR_ABS_X
 #else
