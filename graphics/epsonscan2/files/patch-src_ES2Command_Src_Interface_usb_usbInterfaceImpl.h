--- src/ES2Command/Src/Interface/usb/usbInterfaceImpl.h.orig	2024-09-12 07:10:32 UTC
+++ src/ES2Command/Src/Interface/usb/usbInterfaceImpl.h
@@ -18,7 +18,11 @@
 #pragma once
 
        
+#if __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include "../interfaceImpl.h"
 #include "../interface.h"
 #include "CommonUtility/ESCommonTypedef.h"
