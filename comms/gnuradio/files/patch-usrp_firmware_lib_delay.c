--- usrp/firmware/lib/delay.c.orig	2009-01-21 11:05:07.000000000 -0500
+++ usrp/firmware/lib/delay.c	2012-10-03 20:01:36.000000000 -0500
@@ -24,11 +24,11 @@
  * Delay approximately 1 microsecond (including overhead in udelay).
  */
 static void
-udelay1 (void) _naked
+udelay1 (void)  __naked
 {
-  _asm				; lcall that got us here took 4 bus cycles
+  __asm				; lcall that got us here took 4 bus cycles
 	ret			; 4 bus cycles
-  _endasm;
+  __endasm;
 }
 
 /*
@@ -51,9 +51,9 @@
  * but explains the factor of 4 problem below).
  */
 static void
-mdelay1 (void) _naked
+mdelay1 (void) __naked
 {
-  _asm
+  __asm
 	mov	dptr,#(-1200 & 0xffff)
 002$:	
 	inc	dptr		; 3 bus cycles
@@ -62,7 +62,7 @@
 	jnz	002$		; 3 bus cycles
 
 	ret
-  _endasm;
+  __endasm;
 }
 
 void
