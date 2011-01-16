--- emu10kx.c.orig	2011-01-16 20:03:30.000000000 +0100
+++ emu10kx.c	2011-01-16 20:03:54.000000000 +0100
@@ -892,7 +892,7 @@
 #else
 	sc->irq = bus_alloc_resource(dev, SYS_RES_IRQ, &i, 0, ~0, 1, RF_ACTIVE | RF_SHAREABLE);
 #endif
-	if ((!(sc->irq)) || bus_setup_intr(dev, sc->irq, INTR_MPSAFE | INTR_TYPE_AV, emu_intr, sc, &sc->ih)) {
+	if ((!(sc->irq)) || bus_setup_intr(dev, sc->irq, INTR_MPSAFE | INTR_TYPE_AV, NULL, emu_intr, sc, &sc->ih)) {
 		device_printf(dev, "unable to map interrupt\n");
 		goto bad;
 	}
