--- drivers/vidix/drivers/radeon_vid.c.orig	Wed Oct  2 16:01:05 2002
+++ drivers/vidix/drivers/radeon_vid.c	Wed Oct  2 16:01:15 2002
@@ -11,6 +11,7 @@
 #include <string.h>
 #include <math.h>
 #include <inttypes.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include "../../libdha/pci_ids.h"
 #include "../../libdha/pci_names.h"
