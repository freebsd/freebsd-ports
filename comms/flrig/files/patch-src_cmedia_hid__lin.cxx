--- src/cmedia/hid_lin.cxx.orig	2023-10-05 17:27:21 UTC
+++ src/cmedia/hid_lin.cxx
@@ -35,12 +35,22 @@
 #include <fcntl.h>
 #include <poll.h>
 
+#ifdef __FreeBSD__
+typedef unsigned short uint16_t;
+typedef unsigned char __u8;
+typedef unsigned long __u32;
+#include <dev/hid/hidraw.h>
+/* These are from linux */
+#define BUS_USB			0x03
+#define BUS_BLUETOOTH		0x05
+#include <libudev.h>
+#else
 /* Linux */
 #include <linux/hidraw.h>
 #include <linux/version.h>
 #include <linux/input.h>
 #include <libudev.h>
-
+#endif
 #include "hidapi.h"
 
 /* Definitions from linux/hidraw.h. Since these are new, some distros
