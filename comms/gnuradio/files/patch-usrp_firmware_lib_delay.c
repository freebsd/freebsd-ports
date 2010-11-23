--- usrp/firmware/lib/delay.c.orig	2010-11-19 21:26:31.000000000 -0500
+++ usrp/firmware/lib/delay.c	2010-11-19 21:28:04.000000000 -0500
@@ -24,11 +24,12 @@
  * Delay approximately 1 microsecond (including overhead in udelay).
  */
 static void
-udelay1 (void) _naked
+udelay1 (void) 
+//__naked
 {
-  _asm				; lcall that got us here took 4 bus cycles
+  __asm				; lcall that got us here took 4 bus cycles
 	ret			; 4 bus cycles
-  _endasm;
+  __endasm;
 }
 
 /*
@@ -51,9 +52,10 @@
  * but explains the factor of 4 problem below).
  */
 static void
-mdelay1 (void) _naked
+mdelay1 (void)
+// _naked
 {
-  _asm
+  __asm
 	mov	dptr,#(-1200 & 0xffff)
 002$:	
 	inc	dptr		; 3 bus cycles
@@ -62,7 +64,7 @@
 	jnz	002$		; 3 bus cycles
 
 	ret
-  _endasm;
+  __endasm;
 }
 
 void
