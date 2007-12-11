--- setup/FreeBSD/oss/build/osscore.c.orig	2007-12-11 15:01:24.000000000 -0500
+++ setup/FreeBSD/oss/build/osscore.c	2007-12-11 15:06:33.000000000 -0500
@@ -163,9 +163,13 @@
       return -EIO;
     }
 
-  intr->irq == bus_setup_intr (osdev->dip, intr->irqres,
-			       INTR_TYPE_AV | INTR_MPSAFE, ossintr, intr,
-			       &(intr->cookie));
+  intr->irq = bus_setup_intr (osdev->dip, intr->irqres,
+			      INTR_TYPE_AV | INTR_MPSAFE,
+#if __FreeBSD_version >= 700031
+			      NULL,
+#endif
+			      ossintr, intr,
+			      &(intr->cookie));
 
   nintrs++;
 
