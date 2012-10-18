--- usrp/firmware/src/usrp2/spi.h.orig	2012-10-03 19:18:32.000000000 -0500
+++ usrp/firmware/src/usrp2/spi.h	2012-10-03 19:18:59.000000000 -0500
@@ -31,13 +31,13 @@
 unsigned char
 spi_read (unsigned char header_hi, unsigned char header_lo,
 	  unsigned char enables, unsigned char format,
-	  xdata unsigned char *buf, unsigned char len);
+	  __xdata unsigned char *buf, unsigned char len);
 
 // returns non-zero if successful, else 0
 unsigned char
 spi_write (unsigned char header_hi, unsigned char header_lo,
 	   unsigned char enables, unsigned char format,
-	   const xdata unsigned char *buf, unsigned char len);
+	   const __xdata unsigned char *buf, unsigned char len);
 
 
 #endif /* INCLUDED_SPI_H */
