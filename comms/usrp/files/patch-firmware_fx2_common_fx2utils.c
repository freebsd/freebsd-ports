--- firmware/fx2/common/fx2utils.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/fx2utils.c	2012-10-07 19:36:47.000000000 -0500
@@ -42,8 +42,9 @@
 {
   USBCS |= bmDISCON | bmRENUM;
 
-  // mdelay (1500);		// FIXME why 1.5 seconds?
-  mdelay (250);			// FIXME why 1.5 seconds?
+  mdelay (1500);		// FIXME why 1.5 seconds?
+// Does not seem to settle fast enough on some USRPs -- db
+//  mdelay (250);			// FIXME why 1.5 seconds?
   
   USBIRQ = 0xff;		// clear any pending USB irqs...
   EPIRQ =  0xff;		//   they're from before the renumeration
