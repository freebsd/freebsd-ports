--- src/platform/XWindow.h_orig	Sat Jan 24 23:22:56 2004
+++ src/platform/XWindow.h	Sat Jan 24 23:23:25 2004
@@ -35,7 +35,12 @@
 extern "C" {
 #endif
 #ifdef __FreeBSD__
-#include <libusb.h>
+# include <osreldate.h>
+# if __FreeBSD_version >= 500111
+#  include <usbhid.h>
+# else
+#  include <libusbhid.h>
+# endif
 #else
 #include <usb.h>
 #endif
