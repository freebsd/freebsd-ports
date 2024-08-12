https://github.com/minetest/minetest/pull/14962

--- irr/src/CIrrDeviceLinux.cpp.orig	2024-08-11 15:54:55 UTC
+++ irr/src/CIrrDeviceLinux.cpp
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
