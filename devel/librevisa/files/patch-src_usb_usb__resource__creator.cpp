--- src/usb/usb_resource_creator.cpp.orig	2013-04-08 15:47:56 UTC
+++ src/usb/usb_resource_creator.cpp
@@ -293,7 +293,7 @@ bool usb_resource::creator::open_device_and_get_serial
         {
                 uint8_t bLength;
                 uint8_t bDescriptorType;
-                uint16_t bString[0];
+                char16_t bString[0];
         };
 
         /// @todo may not be portable everywhere
