--- src/VBox/Main/src-server/freebsd/USBProxyBackendFreeBSD.cpp.orig	2016-08-16 20:00:20 UTC
+++ src/VBox/Main/src-server/freebsd/USBProxyBackendFreeBSD.cpp
@@ -299,21 +299,21 @@ PUSBDEVICE USBProxyBackendFreeBSD::getDe
 
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
