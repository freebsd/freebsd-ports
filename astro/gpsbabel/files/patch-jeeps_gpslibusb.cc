--- jeeps/gpslibusb.cc.orig	2020-09-12 23:57:25 UTC
+++ jeeps/gpslibusb.cc
@@ -32,7 +32,7 @@
 // We use our own libusb.
 #    include "mac/libusb/libusb.h"
 #  else
-#    include <libusb-1.0/libusb.h>
+#    include <libusb.h>
 #  endif
 #include "../defs.h"
 #include "garminusb.h"
