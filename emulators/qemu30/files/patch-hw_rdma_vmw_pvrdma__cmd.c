--- hw/rdma/vmw/pvrdma_cmd.c.orig	2019-04-12 03:28:28 UTC
+++ hw/rdma/vmw/pvrdma_cmd.c
@@ -16,7 +16,6 @@
 #include "qemu/osdep.h"
 #include "qemu/error-report.h"
 #include "cpu.h"
-#include <linux/types.h>
 #include "hw/hw.h"
 #include "hw/pci/pci.h"
 #include "hw/pci/pci_ids.h"
