
$FreeBSD$

--- au88x0.c.orig	Fri May 10 10:32:55 2002
+++ au88x0.c	Thu Aug  5 05:44:30 2004
@@ -29,10 +29,16 @@
  */
 
 #include <dev/sound/pcm/sound.h>
-#include <dev/sound/pci/au88x0.h>
+#include "au88x0.h"
+#include <sys/systm.h>
 
+#if __FreeBSD_version < 500000
 #include <pci/pcireg.h>
 #include <pci/pcivar.h>
+#else
+#include <dev/pci/pcireg.h>
+#include <dev/pci/pcivar.h>
+#endif
 #include <sys/queue.h>
 
 SND_DECLARE_FILE("$FreeBSD$");
@@ -852,7 +858,11 @@
 		/*highaddr*/BUS_SPACE_MAXADDR,
 		/*filter*/NULL, /*filterarg*/NULL,
 		/*maxsize*/AU_BUFFSIZE, /*nsegments*/1, /*maxsegz*/0x3ffff,
-		/*flags*/0, &au->parent_dmat) != 0) {
+		/*flags*/0,
+#if __FreeBSD_version > 501102
+		/*lockfunc*/NULL, /*lockarg*/NULL,
+#endif
+                &au->parent_dmat) != 0) {
 		device_printf(dev, "unable to create dma tag\n");
 		goto bad;
 	}
@@ -942,6 +952,10 @@
 
 
 DRIVER_MODULE(snd_au88x0, pci, au_driver, pcm_devclass, 0, 0);
+#if __FreeBSD_version > 502124
+MODULE_DEPEND(snd_au88x0, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
+#else
 MODULE_DEPEND(snd_au88x0, snd_pcm, PCM_MINVER, PCM_PREFVER, PCM_MAXVER);
+#endif
 MODULE_VERSION(snd_au88x0, 1);
 
