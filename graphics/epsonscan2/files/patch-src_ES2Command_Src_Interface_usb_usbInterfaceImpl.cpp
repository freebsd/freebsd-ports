--- src/ES2Command/Src/Interface/usb/usbInterfaceImpl.cpp.orig	2021-11-25 00:56:54 UTC
+++ src/ES2Command/Src/Interface/usb/usbInterfaceImpl.cpp
@@ -46,7 +46,8 @@ USBInterfaceImpl::USBInterfaceImpl()
             sm_ctx = nullptr;
             throw std::runtime_error("unable to initialise USB support");
         }
-        libusb_set_debug(sm_ctx, 3);
+	// XXX this cannot be left enabled as the debug messages go to stdout which is where the scan image data goes
+        //libusb_set_debug(sm_ctx, 3);
     }
     ++sm_nConnectionCount;
 }
