
$FreeBSD$

--- au88x0.c.orig	Mon Jan 15 18:44:49 2001
+++ au88x0.c	Mon Jan 15 18:44:49 2001
@@ -32,7 +32,8 @@
  */
 
 #include <dev/sound/pcm/sound.h>
-#include <dev/sound/pci/au88x0.h>
+#include "au88x0.h"
+#include <sys/systm.h>
 
 #include <pci/pcireg.h>
 #include <pci/pcivar.h>
@@ -852,7 +853,11 @@
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
