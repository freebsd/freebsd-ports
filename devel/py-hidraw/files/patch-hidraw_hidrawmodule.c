--- hidraw/hidrawmodule.c.orig	2021-03-15 09:48:56 UTC
+++ hidraw/hidrawmodule.c
@@ -1,6 +1,10 @@
 #include <Python.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <dev/hid/hidraw.h>
+#else
 #include <linux/hidraw.h>
+#endif
 
 struct module_state {
 };
