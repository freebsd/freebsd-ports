--- _Unix-X/libxpce/xvhandler.c.orig	Thu Jul 24 03:04:02 2003
+++ _Unix-X/libxpce/xvhandler.c	Thu Jul 24 03:04:12 2003
@@ -342,7 +342,7 @@
 
 /* x_DCTCEDoComp() - Do one component for DCTCE */
 int x_DCTCEDoComp(int mask, int color) {
-  static const char cnames[] = { "red", "green", "blue" };
+  static const char *cnames[] = { "red", "green", "blue" };
   static const char cflags[] = { DoRed, DoGreen, DoBlue }; 
   static unsigned long int * const carrays[] = { X_redmap, 
 						 X_greenmap, 
