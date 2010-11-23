--- usrp/firmware/src/common/fpga_load.c.orig	2010-11-19 22:24:42.000000000 -0500
+++ usrp/firmware/src/common/fpga_load.c	2010-11-19 22:25:05.000000000 -0500
@@ -89,7 +89,8 @@
 #else
 
 static void 
-clock_out_config_byte (unsigned char bits) _naked
+clock_out_config_byte (unsigned char bits)
+// _naked
 {
     _asm
 	mov	a, dpl
