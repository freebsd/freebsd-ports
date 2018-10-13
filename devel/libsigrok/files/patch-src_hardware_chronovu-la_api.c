--- src/hardware/chronovu-la/api.c.orig
+++ src/hardware/chronovu-la/api.c
@@ -200,10 +200,10 @@
 			continue;
 		}
 
-		usb_get_port_path(devlist[i], connection_id, sizeof(connection_id));
-
 		libusb_close(hdl);
 
+		usb_get_port_path(devlist[i], connection_id, sizeof(connection_id));
+
 		if (!strcmp(product, "ChronoVu LA8")) {
 			model = 0;
 		} else if (!strcmp(product, "ChronoVu LA16")) {
