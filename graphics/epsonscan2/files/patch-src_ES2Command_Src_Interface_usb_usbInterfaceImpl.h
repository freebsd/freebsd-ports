--- src/ES2Command/Src/Interface/usb/usbInterfaceImpl.h.orig	2021-11-25 00:56:54 UTC
+++ src/ES2Command/Src/Interface/usb/usbInterfaceImpl.h
@@ -20,8 +20,11 @@
 //  usbInterfaceImpl.h -- template and derived ESC/I ESC/I-2 protocol commands
 #pragma once
 
-       
+#if __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include "../interfaceImpl.h"
 #include "../interface.h"
 class USBInterfaceImpl : public IInterfaceImpl
