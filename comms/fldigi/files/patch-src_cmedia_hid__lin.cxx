--- src/cmedia/hid_lin.cxx.orig	2023-08-04 01:13:37 UTC
+++ src/cmedia/hid_lin.cxx
@@ -35,10 +35,20 @@
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
+#else
 /* Linux */
 #include <linux/hidraw.h>
 #include <linux/version.h>
 #include <linux/input.h>
+#endif
 #include <libudev.h>
 
 #include "hidapi.h"
