--- au88x0.c.orig	2002-05-10 09:32:55.000000000 +0800
+++ au88x0.c	2009-02-21 16:14:41.000000000 +0800
@@ -30,8 +30,9 @@
 
 #include <dev/sound/pcm/sound.h>
-#include <dev/sound/pci/au88x0.h>
+#include "au88x0.h"
+#include <sys/systm.h>
 
-#include <pci/pcireg.h>
-#include <pci/pcivar.h>
+#include <dev/pci/pcireg.h>
+#include <dev/pci/pcivar.h>
 #include <sys/queue.h>
 
@@ -574,5 +575,9 @@
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
@@ -769,5 +774,5 @@
 
 	if (s) device_set_desc(dev, s);
-	return s ? 0 : ENXIO;
+	return s ? BUS_PROBE_DEFAULT : ENXIO;
 }
 
@@ -803,5 +808,5 @@
 
 	for (i = 0; i < 3; i++) {
-		au->regid[i] = PCIR_MAPS + i*4;
+		au->regid[i] = PCIR_BAR(i);
 		au->regtype[i] = SYS_RES_MEMORY;
 		au->reg[i] = bus_alloc_resource(dev, au->regtype[i], &au->regid[i], 0, ~0, 1, RF_ACTIVE);
@@ -853,5 +858,7 @@
 		/*filter*/NULL, /*filterarg*/NULL,
 		/*maxsize*/AU_BUFFSIZE, /*nsegments*/1, /*maxsegz*/0x3ffff,
-		/*flags*/0, &au->parent_dmat) != 0) {
+		/*flags*/0,
+		/*lockfunc*/NULL, /*lockarg*/NULL,
+                &au->parent_dmat) != 0) {
 		device_printf(dev, "unable to create dma tag\n");
 		goto bad;
@@ -943,5 +950,5 @@
 
 DRIVER_MODULE(snd_au88x0, pci, au_driver, pcm_devclass, 0, 0);
-MODULE_DEPEND(snd_au88x0, snd_pcm, PCM_MINVER, PCM_PREFVER, PCM_MAXVER);
+MODULE_DEPEND(snd_au88x0, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
 MODULE_VERSION(snd_au88x0, 1);
 
