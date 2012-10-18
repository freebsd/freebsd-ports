--- usrp/firmware/src/usrp2/board_specific.c.orig	2012-10-03 19:29:27.000000000 -0500
+++ usrp/firmware/src/usrp2/board_specific.c	2012-10-03 19:29:52.000000000 -0500
@@ -64,7 +64,7 @@
   // NOP on usrp1
 }
 
-static xdata unsigned char xbuf[1];
+static __xdata unsigned char xbuf[1];
 
 void
 write_9862 (unsigned char which, unsigned char regno, unsigned char value)
