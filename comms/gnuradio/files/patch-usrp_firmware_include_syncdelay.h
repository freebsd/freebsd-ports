--- usrp/firmware/include/syncdelay.h.orig	2012-10-03 19:01:59.000000000 -0500
+++ usrp/firmware/include/syncdelay.h	2012-10-03 19:04:30.000000000 -0500
@@ -58,8 +58,8 @@
 /*
  * FIXME ensure that the peep hole optimizer isn't screwing us
  */
-#define	SYNCDELAY	_asm nop; nop; nop; _endasm
-#define	NOP		_asm nop; _endasm
+#define	SYNCDELAY	__asm nop; nop; nop; __endasm
+#define	NOP		__asm nop; __endasm
 
 
 #endif /* _SYNCDELAY_H_ */
