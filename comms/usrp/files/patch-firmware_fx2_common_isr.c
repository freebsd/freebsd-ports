--- firmware/fx2/common/isr.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/isr.c	2012-10-07 19:37:47.000000000 -0500
@@ -24,9 +24,9 @@
 #include "fx2regs.h"
 #include "syncdelay.h"
 
-extern xdata unsigned char _standard_interrupt_vector[];
-extern xdata unsigned char _usb_autovector[];
-extern xdata unsigned char _fifo_gpif_autovector[];
+extern __xdata unsigned char _standard_interrupt_vector[];
+extern __xdata unsigned char _usb_autovector[];
+extern __xdata unsigned char _fifo_gpif_autovector[];
 
 #define LJMP_OPCODE	0x02
 
@@ -39,7 +39,7 @@
 void 
 hook_sv (unsigned char vector_number, unsigned short addr)
 {
-  bit	t;
+  __bit	t;
   
   // sanity checks
 
@@ -66,7 +66,7 @@
 void 
 hook_uv (unsigned char vector_number, unsigned short addr)
 {
-  bit	t;
+  __bit	t;
   
   // sanity checks
 
@@ -93,7 +93,7 @@
 void 
 hook_fgv (unsigned char vector_number, unsigned short addr)
 {
-  bit	t;
+  __bit	t;
   
   // sanity checks
 
