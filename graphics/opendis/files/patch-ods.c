--- src/ods.c.orig	Tue May 22 13:32:19 2001
+++ src/ods.c	Tue May 22 13:32:38 2001
@@ -199,7 +199,7 @@
   printf("OPTIONS are now supported.\n\n");
 
   printf("  -d DEV, --device=DEV       Look for camera at device DEV.  Defaults\n");
-  printf("                             to /dev/ttyS0.\n");
+  printf("                             to /dev/cuaa0.\n");
   printf("  -r RATE, --rate=RATE       Use bit-rate RATE for serial device.  Defaults\n");
   printf("                             to 9600.  Not applicable to USB or IrDA.\n");
   printf("  -t TYPE, --type=TYPE       Specifies device type, one of: \"serial\"\n");
