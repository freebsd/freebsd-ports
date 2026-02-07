--- libg19.c.orig	2010-04-13 04:13:54.000000000 +0200
+++ libg19.c	2011-04-16 08:25:58.000000000 +0200
@@ -20,6 +20,7 @@
 #include <libusb.h>
 #include <pthread.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
@@ -353,52 +354,54 @@
 }
 
 /**
- * Sends raw data to the lcd without formatting
+ * Sends the data to screen
  * 
  * @param data pointer to the screen data
- * @param len amount of data to be written in bytes
+ * @param size size of the data to be written in bytes
+ * @param flags options for the function to use for updating
  **/
-void g19_update_lcd(unsigned char * data, int len)
+void g19_update_lcd(unsigned char * data, size_t size, unsigned int flags)
 {
-	struct libusb_transfer * lcd_transfer = libusb_alloc_transfer(0);
-	lcd_transfer -> flags = LIBUSB_TRANSFER_FREE_TRANSFER;
-	
-	libusb_fill_bulk_transfer(lcd_transfer, g19_devh, 0x02, data, len, NULL, NULL, 0);
-	libusb_submit_transfer(lcd_transfer);
-}
-
-/**
- * Prepends the header data to the screen data
- * Formats the bitmap data
- * Writes the result to the screen
- * 
- * @param data pointer to the bitmap data
- * @param len amount of data to be written in bytes
- **/
-void g19_update_lcd_bmp(unsigned char * data, int len)
-{
-	unsigned char bits[G19_BMP_SIZE];
-	
-	if(g19_devh == NULL)
+	if((g19_devh == NULL) || (size < 1))
 		return;
 	
-	memset(&bits, 0x00, sizeof(bits));
-	memcpy(&bits, &hdata, sizeof(hdata));
+	struct libusb_transfer * lcd_transfer;
+	size_t bsize = G19_BMP_SIZE;
+	unsigned char * bits = malloc(bsize);
 	
+	lcd_transfer = libusb_alloc_transfer(0);
+	lcd_transfer -> flags = LIBUSB_TRANSFER_FREE_TRANSFER;
 	
-	int i, d;
-	unsigned int color;
+	memset(bits, 0x00, bsize);
 	
-	for(i = sizeof(hdata); (i < G19_BMP_SIZE) && (d < len); i += 2, d += 4)
+	if((flags & G19_PREPEND_HDATA) || (flags & G19_DATA_TYPE_BMP))
 	{
-		color = (data[d] / 8) << 11;
-		color |= (data[d + 1] / 4) << 5;
-		color |= data[d + 2] / 8;
+		lcd_transfer -> flags |= LIBUSB_TRANSFER_FREE_BUFFER;
+		memcpy(bits, hdata, sizeof(hdata));
+		
+		if(flags & G19_DATA_TYPE_BMP)
+		{
+			int i, d;
+			unsigned int color;
+			
+			for(i = sizeof(hdata), d = 0; (i < bsize) && (d < size); i += 2, d += 4)
+			{
+				color = (data[d] / 8) << 11;
+				color |= (data[d + 1] / 4) << 5;
+				color |= data[d + 2] / 8;
+				
+				memcpy(bits + i, &color, 2);
+			}
+		}
+		else if(flags & G19_PREPEND_HDATA)
+			memcpy(bits + sizeof(hdata), data, ((size + sizeof(hdata)) > bsize) ? (bsize - sizeof(hdata)) : size);
 		
-		memcpy(bits + i, &color, 2);
+		libusb_fill_bulk_transfer(lcd_transfer, g19_devh, 0x02, bits, bsize, NULL, NULL, 0);
 	}
+	else
+		libusb_fill_bulk_transfer(lcd_transfer, g19_devh, 0x02, data, size, NULL, NULL, 0);
 	
-	g19_update_lcd(bits, G19_BMP_SIZE);
+	libusb_submit_transfer(lcd_transfer);
 }
 
 /**
@@ -410,7 +413,7 @@
  * 
  * @return non zero on error
  **/
-int g19_set_backlight(int r, int g, int b)
+int g19_set_backlight(unsigned char r, unsigned char g, unsigned char b)
 {
 	if(g19_devh == NULL)
 		return -1;
