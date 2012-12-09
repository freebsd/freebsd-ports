--- firmware/fx2/b100/fpga_load.c.orig	2012-10-10 13:41:50.000000000 -0500
+++ firmware/fx2/b100/fpga_load.c	2012-10-10 16:37:38.000000000 -0500
@@ -82,9 +82,9 @@
 #else
 
 static void 
-clock_out_config_byte (unsigned char bits) _naked
+clock_out_config_byte (unsigned char bits) __naked
 {
-    _asm
+    __asm
 	mov	a, dpl
 	
 	rlc	a
@@ -129,14 +129,14 @@
 	
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
@@ -156,7 +156,7 @@
  *	ALTERA_NSTATUS = 1 (input)
  */
 unsigned char
-fpga_load_xfer (xdata unsigned char *p, unsigned char bytecount)
+fpga_load_xfer (__xdata unsigned char *p, unsigned char bytecount)
 {
   clock_out_bytes (bytecount, p);
   return 1;
