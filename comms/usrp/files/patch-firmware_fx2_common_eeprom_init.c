--- firmware/fx2/common/eeprom_init.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/eeprom_init.c	2012-10-07 20:10:02.000000000 -0500
@@ -28,7 +28,7 @@
  * into hash1.
  */
 #define	  USRP_HASH_SIZE      16
-xdata at USRP_HASH_SLOT_0_ADDR unsigned char hash0[USRP_HASH_SIZE];
+__xdata __at USRP_HASH_SLOT_0_ADDR unsigned char hash0[USRP_HASH_SIZE];
 
 
 #define REG_RX_PWR_DN		 1
