
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
