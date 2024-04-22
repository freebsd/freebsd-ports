--- lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2023-10-27 15:48:29 UTC
+++ lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp
@@ -45,6 +45,10 @@
 #include <X11/Xcursor/Xcursor.h>
 #endif
 
+#ifdef _IRR_COMPILE_WITH_X11_
+#include <unistd.h> // for getpid()
+#endif
+
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
 #include <unistd.h>
