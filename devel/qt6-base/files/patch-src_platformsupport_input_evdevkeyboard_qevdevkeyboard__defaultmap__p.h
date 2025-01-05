--- src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h.orig	2024-09-18 16:48:24 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h
@@ -17,9 +17,7 @@
 
 #include "qnamespace.h"
 #include "private/qglobal_p.h"
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif !defined(Q_OS_VXWORKS)
+#if !defined(Q_OS_VXWORKS)
 #include "linux/input.h"
 #endif
 
