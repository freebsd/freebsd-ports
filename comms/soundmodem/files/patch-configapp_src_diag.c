--- configapp/src/diag.c.orig	2013-12-13 14:39:25.388350545 -0500
+++ configapp/src/diag.c	2013-12-13 14:40:12.600347047 -0500
@@ -473,7 +473,7 @@
                                         cp += sprintf(cp, "%c", diagstate.p3d.packet[i+j]);
                         }
                 }
-                cp += sprintf(cp, "\n%04x: %02x %02x%44s", 512, diagstate.p3d.packet[512], diagstate.p3d.packet[514], " ");
+                cp += sprintf(cp, "\n%04x: %02x %02x%44s", 512, diagstate.p3d.packet[512], diagstate.p3d.packet[513], " ");
                 for (i = 512; i < 514; i++) {
                         if (diagstate.p3d.packet[i] < ' ' || diagstate.p3d.packet[i] >= 0x80)
                                 cp += sprintf(cp, ".");
