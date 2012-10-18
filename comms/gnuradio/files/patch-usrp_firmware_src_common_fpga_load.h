--- usrp/firmware/src/common/fpga_load.h.orig	2012-10-03 19:17:59.000000000 -0500
+++ usrp/firmware/src/common/fpga_load.h	2012-10-03 19:18:11.000000000 -0500
@@ -22,7 +22,7 @@
 #define INCLUDED_FPGA_LOAD_H
 
 unsigned char fpga_load_begin (void);
-unsigned char fpga_load_xfer (xdata unsigned char *p, unsigned char len);
+unsigned char fpga_load_xfer (__xdata unsigned char *p, unsigned char len);
 unsigned char fpga_load_end (void);
 
 #endif /* INCLUDED_FPGA_LOAD_H */
