--- setup/FreeBSD/oss/build/osscore.c.orig	2007-06-12 08:22:35.000000000 -0400
+++ setup/FreeBSD/oss/build/osscore.c	2007-07-11 18:45:01.000000000 -0400
@@ -164,7 +164,11 @@
     }
 
   intr->irq == bus_setup_intr (osdev->dip, intr->irqres,
-			       INTR_TYPE_AV | INTR_MPSAFE, ossintr, intr,
+			       INTR_TYPE_AV | INTR_MPSAFE,
+#if __FreeBSD_version >= 700031
+			       NULL,
+#endif
+			       ossintr, intr,
 			       &(intr->cookie));
 
   nintrs++;
