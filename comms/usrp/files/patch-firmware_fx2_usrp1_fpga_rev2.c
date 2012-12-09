--- firmware/fx2/usrp1/fpga_rev2.c.orig	2012-10-10 13:24:09.000000000 -0500
+++ firmware/fx2/usrp1/fpga_rev2.c	2012-10-10 13:24:24.000000000 -0500
@@ -30,7 +30,7 @@
 unsigned char g_rx_reset = 0;
 
 void
-fpga_write_reg (unsigned char regno, const xdata unsigned char *regval)
+fpga_write_reg (unsigned char regno, const __xdata unsigned char *regval)
 {
   spi_write (0, 0x00 | (regno & 0x7f),
 	     SPI_ENABLE_FPGA,
@@ -39,7 +39,7 @@
 }
 
 
-static xdata unsigned char regval[4] = {0, 0, 0, 0};
+static __xdata unsigned char regval[4] = {0, 0, 0, 0};
 
 static void
 write_fpga_master_ctrl (void)
