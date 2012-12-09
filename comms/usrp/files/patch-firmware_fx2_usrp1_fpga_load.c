--- firmware/fx2/usrp1/fpga_load.c.orig	2012-10-10 13:23:35.000000000 -0500
+++ firmware/fx2/usrp1/fpga_load.c	2012-10-10 16:28:26.000000000 -0500
@@ -89,9 +89,9 @@
 #else
 
 static void 
-clock_out_config_byte (unsigned char bits) _naked
+clock_out_config_byte (unsigned char bits) __naked
 {
-    _asm
+    __asm
 	mov	a, dpl
 	
 	rrc	a
@@ -136,14 +136,14 @@
 	
 	ret	
 
-    _endasm;
+    __endasm;
 }
 
 #endif
 
 static void
 clock_out_bytes (unsigned char bytecount,
-		 unsigned char xdata *p)
+		 unsigned char __xdata *p)
 {
   while (bytecount-- > 0)
     clock_out_config_byte (*p++);
@@ -163,7 +163,7 @@
  *	ALTERA_NSTATUS = 1 (input)
  */
 unsigned char
-fpga_load_xfer (xdata unsigned char *p, unsigned char bytecount)
+fpga_load_xfer (__xdata unsigned char *p, unsigned char bytecount)
 {
   clock_out_bytes (bytecount, p);
   return 1;
