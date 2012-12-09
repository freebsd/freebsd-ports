--- firmware/fx2/b100/fpga_rev2.c.orig	2012-10-10 13:42:24.000000000 -0500
+++ firmware/fx2/b100/fpga_rev2.c	2012-10-10 13:42:45.000000000 -0500
@@ -29,13 +29,13 @@
 unsigned char g_rx_reset = 0;
 
 void
-fpga_write_reg (unsigned char regno, const xdata unsigned char *regval)
+fpga_write_reg (unsigned char regno, const __xdata unsigned char *regval)
 {
 	//nop
 }
 
 
-static xdata unsigned char regval[4] = {0, 0, 0, 0};
+static __xdata unsigned char regval[4] = {0, 0, 0, 0};
 
 // Resets both AD9862's and the FPGA serial bus interface.
 
