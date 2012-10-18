--- usrp/firmware/include/i2c.h.orig	2012-10-03 18:58:56.000000000 -0500
+++ usrp/firmware/include/i2c.h	2012-10-03 19:13:39.000000000 -0500
@@ -24,9 +24,9 @@
 #define _I2C_H_
 
 // returns non-zero if successful, else 0
-unsigned char i2c_read (unsigned char addr, xdata unsigned char *buf, unsigned char len);
+unsigned char i2c_read (unsigned char addr, __xdata unsigned char *buf, unsigned char len);
 
 // returns non-zero if successful, else 0
-unsigned char i2c_write (unsigned char addr, xdata const unsigned char *buf, unsigned char len);
+unsigned char i2c_write (unsigned char addr, __xdata const unsigned char *buf, unsigned char len);
 
 #endif /* _I2C_H_ */
