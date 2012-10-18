--- usrp/firmware/src/usrp2/eeprom_init.c.orig	2012-10-03 19:27:16.000000000 -0500
+++ usrp/firmware/src/usrp2/eeprom_init.c	2012-10-03 19:27:32.000000000 -0500
@@ -29,7 +29,7 @@
  * into hash1.
  */
 #define	  USRP_HASH_SIZE      16
-xdata at USRP_HASH_SLOT_0_ADDR unsigned char hash0[USRP_HASH_SIZE];
+__xdata at USRP_HASH_SLOT_0_ADDR unsigned char hash0[USRP_HASH_SIZE];
 
 
 #define enable_codecs() USRP_PA &= ~(bmPA_SEN_CODEC_A | bmPA_SEN_CODEC_B)
