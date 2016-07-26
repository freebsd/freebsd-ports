--- au88x0.c.orig	2016-07-26 13:37:02 UTC
+++ au88x0.c
@@ -33,10 +33,11 @@
  */
 
 #include <dev/sound/pcm/sound.h>
-#include <dev/sound/pci/au88x0.h>
+#include "au88x0.h"
+#include <sys/systm.h>
 
-#include <pci/pcireg.h>
-#include <pci/pcivar.h>
+#include <dev/pci/pcireg.h>
+#include <dev/pci/pcivar.h>
 #include <sys/queue.h>
 
 SND_DECLARE_FILE("$FreeBSD$");
@@ -577,7 +578,11 @@ auchan_init(kobj_t obj, void *devinfo, s
 	ch->channel = c;
 	ch->buffer = b;
 	ch->run = 0;
-	if (sndbuf_alloc(ch->buffer, au->parent_dmat, AU_BUFFSIZE) == -1) {
+	if (sndbuf_alloc(ch->buffer, au->parent_dmat,
+#if __FreeBSD_version >= 700037
+					0,
+#endif
+					AU_BUFFSIZE) != 0) {
 		printf("sndbuf_alloc failed\n");
 		return NULL;
 	}
@@ -769,7 +774,7 @@ au_pci_probe(device_t dev)
 	}
 
 	if (s) device_set_desc(dev, s);
-	return s ? 0 : ENXIO;
+	return s ? BUS_PROBE_DEFAULT : ENXIO;
 }
 
 static int
@@ -803,7 +808,7 @@ au_pci_attach(device_t dev)
 	data = pci_read_config(dev, PCIR_COMMAND, 2);
 
 	for (i = 0; i < 3; i++) {
-		au->regid[i] = PCIR_MAPS + i*4;
+		au->regid[i] = PCIR_BAR(i);
 		au->regtype[i] = SYS_RES_MEMORY;
 		au->reg[i] = bus_alloc_resource(dev, au->regtype[i], &au->regid[i], 0, ~0, 1, RF_ACTIVE);
 		if (!au->reg[i]) {
@@ -853,7 +858,9 @@ au_pci_attach(device_t dev)
 		/*highaddr*/BUS_SPACE_MAXADDR,
 		/*filter*/NULL, /*filterarg*/NULL,
 		/*maxsize*/AU_BUFFSIZE, /*nsegments*/1, /*maxsegz*/0x3ffff,
-		/*flags*/0, &au->parent_dmat) != 0) {
+		/*flags*/0,
+		/*lockfunc*/NULL, /*lockarg*/NULL,
+                &au->parent_dmat) != 0) {
 		device_printf(dev, "unable to create dma tag\n");
 		goto bad;
 	}
@@ -943,6 +950,6 @@ static driver_t au_driver = {
 
 
 DRIVER_MODULE(snd_au88x0, pci, au_driver, pcm_devclass, 0, 0);
-MODULE_DEPEND(snd_au88x0, snd_pcm, PCM_MINVER, PCM_PREFVER, PCM_MAXVER);
+MODULE_DEPEND(snd_au88x0, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
 MODULE_VERSION(snd_au88x0, 1);
 
