--- firmware/fx2/b100/eeprom_io.h.orig	2012-10-10 16:55:20.000000000 -0500
+++ firmware/fx2/b100/eeprom_io.h	2012-10-10 16:55:36.000000000 -0500
@@ -27,12 +27,12 @@
 // returns non-zero if successful, else 0
 unsigned char
 eeprom_read (unsigned char i2c_addr, unsigned char eeprom_offset,
-	     xdata unsigned char *buf, unsigned char len);
+	     __xdata unsigned char *buf, unsigned char len);
 
 // returns non-zero if successful, else 0
 unsigned char
 eeprom_write (unsigned char i2c_addr, unsigned char eeprom_offset,
-	      const xdata unsigned char *buf, unsigned char len);
+	      const __xdata unsigned char *buf, unsigned char len);
 
 
 #endif /* INCLUDED_EEPROM_IO_H */
