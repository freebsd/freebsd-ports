--- lib/fbsd-device.c.orig	Fri Jun 13 11:11:29 2003
+++ lib/fbsd-device.c	Fri Jun 13 11:21:52 2003
@@ -14,9 +14,19 @@
 #include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
+#include <osreldate.h>
 
-#include <pci/pcivar.h>
-#include <pci/pci_ioctl.h>
+#if __FreeBSD_version < 500000
+#  include <pci/pcivar.h>
+#else
+#  include <dev/pci/pcivar.h>
+#endif
+
+#if __FreeBSD_version < 430000
+#  include <pci/pci_ioctl.h>
+#else
+#  include <sys/pciio.h>
+#endif
 
 #include "internal.h"
 
