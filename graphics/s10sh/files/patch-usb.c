--- usb.c.orig	Tue Mar 13 06:46:18 2001
+++ usb.c	Sat Dec  7 06:16:19 2002
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
@@ -97,6 +103,12 @@
 						printf("Canon G1 found\n");
 					return USB_INIT_G1;
 					break;
+				case PRODUCT_ID_G3:
+					*camera_dev = dev;
+					if (opt_debug)
+						printf("Canon G3 found\n");
+					return USB_INIT_G3;
+					break;
 				case PRODUCT_ID_NEXTDIGICAM1:
 				case PRODUCT_ID_NEXTDIGICAM2:
 				case PRODUCT_ID_NEXTDIGICAM3:
@@ -118,6 +130,7 @@
 						dev->descriptor.idProduct);
 					break;
 				}
+				break;
 			default:
 				if (opt_debug)
 					printf("Unknown vendor ID: %04X\n",
