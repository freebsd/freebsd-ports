--- firmware/fx2/usrp1/eeprom_io.c.orig	2012-10-10 13:22:48.000000000 -0500
+++ firmware/fx2/usrp1/eeprom_io.c	2012-10-10 13:23:15.000000000 -0500
@@ -27,12 +27,12 @@
 // returns non-zero if successful, else 0
 unsigned char
 eeprom_read (unsigned char i2c_addr, unsigned char eeprom_offset,
-	     xdata unsigned char *buf, unsigned char len)
+	     __xdata unsigned char *buf, unsigned char len)
 {
   // We setup a random read by first doing a "zero byte write".
   // Writes carry an address.  Reads use an implicit address.
 
-  static xdata unsigned char cmd[1];
+  static __xdata unsigned char cmd[1];
   cmd[0] = eeprom_offset;
   if (!i2c_write(i2c_addr, cmd, 1))
     return 0;
@@ -46,9 +46,9 @@
 // returns non-zero if successful, else 0
 unsigned char
 eeprom_write (unsigned char i2c_addr, unsigned char eeprom_offset,
-	      const xdata unsigned char *buf, unsigned char len)
+	      const __xdata unsigned char *buf, unsigned char len)
 {
-  static xdata unsigned char cmd[2];
+  static __xdata unsigned char cmd[2];
   unsigned char ok;
 
   while (len-- > 0){
