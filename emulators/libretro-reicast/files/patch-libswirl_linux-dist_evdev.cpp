--- libswirl/linux-dist/evdev.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/linux-dist/evdev.cpp
@@ -8,7 +8,11 @@
 
 #include <unistd.h>
 #include <fcntl.h>
+#if defined(__FreeBSD__)
+#include <dev/evdev/input.h>
+#else
 #include <linux/input.h>
+#endif
 #ifdef USE_UDEV
 #include <libudev.h>
 #endif
