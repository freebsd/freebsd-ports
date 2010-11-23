--- usrp/firmware/src/usrp2/spi.c.orig	2010-11-19 22:13:00.000000000 -0500
+++ usrp/firmware/src/usrp2/spi.c	2010-11-19 22:13:12.000000000 -0500
@@ -320,7 +320,8 @@
 }
 #else
 static unsigned char
-read_byte_msb (void) _naked
+read_byte_msb (void)
+// _naked
 {
   _asm
 	clr	a
