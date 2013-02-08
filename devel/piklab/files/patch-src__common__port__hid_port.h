--- src/common/port/hid_port.h.orig
+++ src/common/port/hid_port.h
@@ -9,6 +9,8 @@
 #ifndef HID_PORT_H
 #define HID_PORT_H
 
+#ifdef __linux
+
 #include "port_base.h"
 
 #ifdef Q_OS_UNIX
@@ -57,3 +59,5 @@
 } // namespace
 
 #endif
+
+#endif
