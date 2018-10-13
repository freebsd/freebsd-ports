--- src/hardware/fx2lafw/api.c.orig
+++ src/hardware/fx2lafw/api.c
@@ -325,10 +325,10 @@
 			continue;
 		}
 
-		usb_get_port_path(devlist[i], connection_id, sizeof(connection_id));
-
 		libusb_close(hdl);
 
+		usb_get_port_path(devlist[i], connection_id, sizeof(connection_id));
+
 		prof = NULL;
 		for (j = 0; supported_fx2[j].vid; j++) {
 			if (des.idVendor == supported_fx2[j].vid &&
