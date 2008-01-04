--- setup/FreeBSD/oss/build/osscore.c.orig	2008-01-04 17:53:49.000000000 -0500
+++ setup/FreeBSD/oss/build/osscore.c	2008-01-04 17:55:26.000000000 -0500
@@ -163,12 +163,12 @@
       return -EIO;
     }
 
-  intr->irq == bus_setup_intr (osdev->dip, intr->irqres,
-			       INTR_TYPE_AV | INTR_MPSAFE,
+  intr->irq = bus_setup_intr (osdev->dip, intr->irqres,
+			      INTR_TYPE_AV | INTR_MPSAFE,
 #if __FreeBSD_version >= 700031
-			       NULL,
+			      NULL,
 #endif
-			       ossintr, intr, &(intr->cookie));
+			      ossintr, intr, &(intr->cookie));
 
   nintrs++;
 
