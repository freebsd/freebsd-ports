--- src/platform/XWindow.h.bak	Tue Jun  4 02:39:32 2002
+++ src/platform/XWindow.h	Sun May  4 14:23:23 2003
@@ -35,9 +35,14 @@
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
-#include <usb.h>
+# include <usb.h>
 #endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
