--- firmware/fx2/common/syncdelay.h.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/syncdelay.h	2012-10-10 13:21:36.000000000 -0500
@@ -23,7 +23,7 @@
 #define _SYNCDELAY_H_
 
 /*
- * Magic delay required between access to certain xdata registers (TRM page 15-106).
+ * Magic delay required between access to certain __xdata registers (TRM page 15-106).
  * For our configuration, 48 MHz FX2 / 48 MHz IFCLK, we need three cycles.  Each
  * NOP is a single cycle....
  *
@@ -58,8 +58,8 @@
 /*
  * FIXME ensure that the peep hole optimizer isn't screwing us
  */
-#define	SYNCDELAY	_asm nop; nop; nop; _endasm
-#define	NOP		_asm nop; _endasm
+#define	SYNCDELAY	__asm nop; nop; nop; __endasm
+#define	NOP		__asm nop; __endasm
 
 
 #endif /* _SYNCDELAY_H_ */
