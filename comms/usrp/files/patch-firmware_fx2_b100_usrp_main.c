--- firmware/fx2/b100/usrp_main.c.orig	2012-10-10 13:41:00.000000000 -0500
+++ firmware/fx2/b100/usrp_main.c	2012-10-10 16:35:30.000000000 -0500
@@ -54,14 +54,14 @@
 unsigned char g_rx_enable = 0;
 unsigned char g_rx_overrun = 0;
 unsigned char g_tx_underrun = 0;
-bit enable_gpif = 0;
+__bit enable_gpif = 0;
 
 /*
  * the host side fpga loader code pushes an MD5 hash of the bitstream
  * into hash1.
  */
 #define	  USRP_HASH_SIZE      16
-xdata at USRP_HASH_SLOT_1_ADDR unsigned char hash1[USRP_HASH_SIZE];
+__xdata __at USRP_HASH_SLOT_1_ADDR unsigned char hash1[USRP_HASH_SIZE];
 
 //void clear_fpga_data_fifo(void);
 
@@ -220,7 +220,7 @@
  * Toggle led 0
  */
 void
-isr_tick (void) interrupt
+isr_tick (void) __interrupt
 {
   static unsigned char	count = 1;
   
@@ -239,8 +239,8 @@
 void
 patch_usb_descriptors(void)
 {
-  static xdata unsigned char hw_rev;
-  static xdata unsigned char serial_no[SERIAL_NO_LEN];
+  static __xdata unsigned char hw_rev;
+  static __xdata unsigned char serial_no[SERIAL_NO_LEN];
   unsigned char i;
 
   eeprom_read(I2C_ADDR_BOOT, HW_REV_OFFSET, &hw_rev, 1);	// LSB of device id
