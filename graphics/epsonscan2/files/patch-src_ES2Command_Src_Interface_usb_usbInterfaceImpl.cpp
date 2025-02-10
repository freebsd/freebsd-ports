--- src/ES2Command/Src/Interface/usb/usbInterfaceImpl.cpp.orig	2024-09-12 07:10:32 UTC
+++ src/ES2Command/Src/Interface/usb/usbInterfaceImpl.cpp
@@ -34,7 +34,8 @@ USBInterfaceImpl::USBInterfaceImpl()
             sm_ctx = nullptr;
             throw std::runtime_error("unable to initialise USB support");
         }
-        libusb_set_debug(sm_ctx, 3);
+        // XXX this cannot be left enabled as the debug messages go to stdout which is where the scan image data goes
+        // libusb_set_debug(sm_ctx, 3);
     }
     ++sm_nConnectionCount;
 }
