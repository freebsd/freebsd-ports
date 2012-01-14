--- rcxlib/RCX_USBTowerPipe_fbsd.cpp.orig	2012-01-05 18:08:27.000000000 -0600
+++ rcxlib/RCX_USBTowerPipe_fbsd.cpp	2012-01-05 18:13:13.000000000 -0600
@@ -20,6 +20,7 @@
 #include <cstring>
 #include <unistd.h>
 #include <dev/usb/usb.h>
+#include <dev/usb/usb_ioctl.h>
 
 #include "RCX_Pipe.h"
 
@@ -308,15 +309,15 @@
 		return -1;
 	}
 	iov = 1;
-	err = ioctl(fdRd, USB_SET_SHORT_XFER, &iov);
+	err = ioctl(fdRd, USB_SET_RX_SHORT_XFER, &iov);
 	if (fdRd == -1) {
-		perror("ioctl USB_SET_SHORT_XFER");
+		perror("ioctl USB_SET_RX_SHORT_XFER");
 		return -1;
 	}
 	iov = 5000;
-	err = ioctl(fdRd, USB_SET_TIMEOUT, &iov);
+	err = ioctl(fdRd, USB_SET_RX_TIMEOUT, &iov);
 	if (fdRd == -1) {
-		perror("ioctl USB_SET_TIMEOUT");
+		perror("ioctl USB_SET_RX_TIMEOUT");
 		return -1;
 	}
