--- usbio.c.orig	2020-10-01 18:59:21 UTC
+++ usbio.c
@@ -29,6 +29,7 @@
 
 unsigned usb_sequence = 0;
 int tolerate_error = 0, retries = 5000;
+unsigned char usb_packet[0x1400];
 
 void usb_hexdump( char *bytes, int size ) {
 	int n, i;
