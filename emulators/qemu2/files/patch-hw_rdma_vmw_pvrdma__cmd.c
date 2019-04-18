--- hw/rdma/vmw/pvrdma_cmd.c.orig	2018-08-02 21:48:53 UTC
+++ hw/rdma/vmw/pvrdma_cmd.c
@@ -16,7 +16,6 @@
 #include "qemu/osdep.h"
 #include "qemu/error-report.h"
 #include "cpu.h"
-#include <linux/types.h>
 #include "hw/hw.h"
 #include "hw/pci/pci.h"
 #include "hw/pci/pci_ids.h"
