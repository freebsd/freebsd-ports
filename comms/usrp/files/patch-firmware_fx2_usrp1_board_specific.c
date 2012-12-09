--- firmware/fx2/usrp1/board_specific.c.orig	2012-10-10 13:25:42.000000000 -0500
+++ firmware/fx2/usrp1/board_specific.c	2012-10-10 13:25:51.000000000 -0500
@@ -64,7 +64,7 @@
   // NOP on usrp1
 }
 
-static xdata unsigned char xbuf[1];
+static __xdata unsigned char xbuf[1];
 
 void
 write_9862 (unsigned char which, unsigned char regno, unsigned char value)
