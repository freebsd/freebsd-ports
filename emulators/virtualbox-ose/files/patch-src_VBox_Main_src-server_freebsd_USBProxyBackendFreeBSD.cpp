--- src/VBox/Main/src-server/freebsd/USBProxyBackendFreeBSD.cpp.orig	2017-01-17 07:27:22 UTC
+++ src/VBox/Main/src-server/freebsd/USBProxyBackendFreeBSD.cpp
@@ -153,6 +153,12 @@ int USBProxyBackendFreeBSD::releaseDevic
 }
 
 
+bool USBProxyBackendFreeBSD::isFakeUpdateRequired()
+{
+    return true;
+}
+
+
 int USBProxyBackendFreeBSD::wait(RTMSINTERVAL aMillies)
 {
     return RTSemEventWait(mNotifyEventSem, aMillies < 1000 ? 1000 : 5000);
@@ -270,8 +276,9 @@ PUSBDEVICE USBProxyBackendFreeBSD::getDe
                 break;
             }
 
-            pDevice->enmState           = USBDEVICESTATE_UNUSED;
+            pDevice->enmState           = USBDEVICESTATE_USED_BY_HOST_CAPTURABLE;
             pDevice->bBus               = UsbDevInfo.udi_bus;
+            pDevice->bPort              = UsbDevInfo.udi_hubport;
             pDevice->bDeviceClass       = UsbDevInfo.udi_class;
             pDevice->bDeviceSubClass    = UsbDevInfo.udi_subclass;
             pDevice->bDeviceProtocol    = UsbDevInfo.udi_protocol;
@@ -292,28 +299,33 @@ PUSBDEVICE USBProxyBackendFreeBSD::getDe
                     pDevice->enmSpeed = USBDEVICESPEED_HIGH;
                     break;
                 case USB_SPEED_SUPER:
+                    pDevice->enmSpeed = USBDEVICESPEED_SUPER;
+                    break;
                 case USB_SPEED_VARIABLE:
+                    pDevice->enmSpeed = USBDEVICESPEED_VARIABLE;
+                    break;
                 default:
                     pDevice->enmSpeed = USBDEVICESPEED_UNKNOWN;
+                    break;
             }
 
             if (UsbDevInfo.udi_vendor[0] != '\0')
             {
+                USBLibPurgeEncoding(UsbDevInfo.udi_vendor);
                 pDevice->pszManufacturer = RTStrDupN(UsbDevInfo.udi_vendor, sizeof(UsbDevInfo.udi_vendor));
-                USBLibPurgeEncoding(pDevice->pszManufacturer);
             }
 
             if (UsbDevInfo.udi_product[0] != '\0')
             {
+                USBLibPurgeEncoding(UsbDevInfo.udi_product);
                 pDevice->pszProduct = RTStrDupN(UsbDevInfo.udi_product, sizeof(UsbDevInfo.udi_product));
-                USBLibPurgeEncoding(pDevice->pszProduct);
             }
 
             if (UsbDevInfo.udi_serial[0] != '\0')
             {
+                USBLibPurgeEncoding(UsbDevInfo.udi_serial);
                 pDevice->pszSerialNumber = RTStrDupN(UsbDevInfo.udi_serial, sizeof(UsbDevInfo.udi_serial));
-                USBLibPurgeEncoding(pDevice->pszSerialNumber);
-                pDevice->u64SerialHash   = USBLibHashSerial(pDevice->pszSerialNumber);
+                pDevice->u64SerialHash = USBLibHashSerial(UsbDevInfo.udi_serial);
             }
             rc = ioctl(FileUsb, USB_GET_PLUGTIME, &PlugTime);
             if (rc == 0)
@@ -321,7 +333,6 @@ PUSBDEVICE USBProxyBackendFreeBSD::getDe
 
             pDevice->pszAddress = RTStrDup(pszDevicePath);
             pDevice->pszBackend = RTStrDup("host");
-            pDevice->enmState   = USBDEVICESTATE_USED_BY_HOST_CAPTURABLE;
 
             usbLogDevice(pDevice);
 
@@ -337,4 +348,3 @@ PUSBDEVICE USBProxyBackendFreeBSD::getDe
 
     return pDevices;
 }
-
