--- src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h.orig	2022-09-19 10:23:04 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h
@@ -17,11 +17,7 @@
 
 #include "qnamespace.h"
 #include "private/qglobal_p.h"
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include "linux/input.h"
-#endif
 
 // no QT_BEGIN_NAMESPACE, since we include it internally...
 
