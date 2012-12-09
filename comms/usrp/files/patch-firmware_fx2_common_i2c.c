--- firmware/fx2/common/i2c.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/i2c.c	2012-10-07 19:37:38.000000000 -0500
@@ -30,7 +30,7 @@
 
 // returns non-zero if successful, else 0
 unsigned char
-i2c_read (unsigned char addr, xdata unsigned char *buf, unsigned char len)
+i2c_read (unsigned char addr, __xdata unsigned char *buf, unsigned char len)
 {
   volatile unsigned char	junk;
   
@@ -89,7 +89,7 @@
 
 // returns non-zero if successful, else 0
 unsigned char
-i2c_write (unsigned char addr, xdata const unsigned char *buf, unsigned char len)
+i2c_write (unsigned char addr, __xdata const unsigned char *buf, unsigned char len)
 {
   while (I2CS & bmSTOP)		// wait for stop to clear
     ;
