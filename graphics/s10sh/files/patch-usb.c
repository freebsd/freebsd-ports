--- usb.c.orig	Tue Mar 13 14:46:18 2001
+++ usb.c	Sun Apr 21 00:59:11 2002
@@ -84,6 +84,12 @@
 						printf("Canon S20 found\n");
 					return USB_INIT_S20;
 					break;
+				case PRODUCT_ID_A20:
+					*camera_dev = dev;
+					if (opt_debug)
+						printf("Canon A20 found\n");
+					return USB_INIT_A20;
+					break;
 				case PRODUCT_ID_S100_EU:
 				case PRODUCT_ID_S100_US:
 					*camera_dev = dev;
