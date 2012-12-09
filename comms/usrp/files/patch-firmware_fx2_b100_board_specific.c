--- firmware/fx2/b100/board_specific.c.orig	2012-10-10 13:42:54.000000000 -0500
+++ firmware/fx2/b100/board_specific.c	2012-10-10 13:43:04.000000000 -0500
@@ -58,7 +58,7 @@
   // NOP on usrp1
 }
 
-static xdata unsigned char xbuf[1];
+static __xdata unsigned char xbuf[1];
 
 void
 init_board (void)
