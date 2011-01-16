--- libgphoto2_port/usb/libusb.c.old	2011-01-16 15:22:21.000000000 +0100
+++ libgphoto2_port/usb/libusb.c	2011-01-16 15:21:57.000000000 +0100
@@ -824,23 +824,25 @@
 	 * MTP interface descriptions, that's how they can be detected, before
 	 * we try the more esoteric "OS descriptors" (below).
 	 */
-	for (i = 0; i < dev->descriptor.bNumConfigurations; i++) {
-		unsigned int j;
-		for (j = 0; j < dev->config[i].bNumInterfaces; j++) {
-			int k;
-			for (k = 0; k < dev->config[i].interface[j].num_altsetting; k++) {
-				buf[0] = '\0';
-				ret = usb_get_string_simple(devh, 
-					dev->config[i].interface[j].altsetting[k].iInterface, 
-					(char *) buf, 
-					1024);
-				if (ret < 3)
-					continue;
-				if (strcmp((char *) buf, "MTP") == 0) {
-					gp_log (GP_LOG_DEBUG, "mtp matcher", "Configuration %d, interface %d, altsetting %d:\n", i, j, k);
-					gp_log (GP_LOG_DEBUG, "mtp matcher", "   Interface description contains the string \"MTP\"\n");
-					gp_log (GP_LOG_DEBUG, "mtp matcher", "   Device recognized as MTP, no further probing.\n");
-					goto found;
+	if(dev->config) {
+		for (i = 0; i < dev->descriptor.bNumConfigurations; i++) {
+			unsigned int j;
+			for (j = 0; j < dev->config[i].bNumInterfaces; j++) {
+				int k;
+				for (k = 0; k < dev->config[i].interface[j].num_altsetting; k++) {
+					buf[0] = '\0';
+					ret = usb_get_string_simple(devh, 
+						dev->config[i].interface[j].altsetting[k].iInterface, 
+						(char *) buf, 
+						1024);
+					if (ret < 3)
+						continue;
+					if (strcmp((char *) buf, "MTP") == 0) {
+						gp_log (GP_LOG_DEBUG, "mtp matcher", "Configuration %d, interface %d, altsetting %d:\n", i, j, k);
+						gp_log (GP_LOG_DEBUG, "mtp matcher", "   Interface description contains the string \"MTP\"\n");
+						gp_log (GP_LOG_DEBUG, "mtp matcher", "   Device recognized as MTP, no further probing.\n");
+						goto found;
+					}
 				}
 			}
 		}
