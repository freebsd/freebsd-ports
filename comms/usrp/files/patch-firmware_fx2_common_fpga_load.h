--- firmware/fx2/common/fpga_load.h.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/fpga_load.h	2012-10-07 19:38:19.000000000 -0500
@@ -22,7 +22,7 @@
 #define INCLUDED_FPGA_LOAD_H
 
 unsigned char fpga_load_begin (void);
-unsigned char fpga_load_xfer (xdata unsigned char *p, unsigned char len);
+unsigned char fpga_load_xfer (__xdata unsigned char *p, unsigned char len);
 unsigned char fpga_load_end (void);
 
 #endif /* INCLUDED_FPGA_LOAD_H */
