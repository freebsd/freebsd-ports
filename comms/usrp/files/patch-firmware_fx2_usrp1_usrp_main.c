--- firmware/fx2/usrp1/usrp_main.c.orig	2012-10-10 13:25:13.000000000 -0500
+++ firmware/fx2/usrp1/usrp_main.c	2012-10-10 16:30:10.000000000 -0500
@@ -63,7 +63,7 @@
  * into hash1.
  */
 #define	  USRP_HASH_SIZE      16
-xdata at USRP_HASH_SLOT_1_ADDR unsigned char hash1[USRP_HASH_SIZE];
+__xdata __at USRP_HASH_SLOT_1_ADDR unsigned char hash1[USRP_HASH_SIZE];
 
 static void
 get_ep0_data (void)
@@ -305,7 +305,7 @@
  * Toggle led 0
  */
 void
-isr_tick (void) interrupt
+isr_tick (void) __interrupt
 {
   static unsigned char	count = 1;
   
@@ -324,8 +324,8 @@
 void
 patch_usb_descriptors(void)
 {
-  static xdata unsigned char hw_rev;
-  static xdata unsigned char serial_no[8];
+  static __xdata unsigned char hw_rev;
+  static __xdata unsigned char serial_no[8];
   unsigned char i;
 
   eeprom_read(I2C_ADDR_BOOT, HW_REV_OFFSET, &hw_rev, 1);	// LSB of device id
