--- source/games/mitchell.c.orig	Thu Nov 17 17:41:02 2005
+++ source/games/mitchell.c	Thu Nov 17 17:41:34 2005
@@ -451,6 +451,7 @@
 
 static UINT8  pang_port5_r (UINT32 offset) {
   int bit;
+  UINT8 res;
 
   bit = EEPROM_read_bit() << 7;
   // 2 bits are togled in the cpu frame, 1 for the vblank, the other unknown
@@ -458,7 +459,7 @@
 /* if (Machine->gamedrv == &driver_mgakuen2)	/\* hack... music doesn't work otherwise *\/ */
 /* 	bit ^= 0x08; */
 
-  UINT8 res = (input_buffer[0] & 0x7f) | bit;
+  res = (input_buffer[0] & 0x7f) | bit;
   return res;
 }
 
