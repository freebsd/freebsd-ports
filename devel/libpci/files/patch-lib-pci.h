--- lib/pci.h.orig	2020-01-25 19:42:39 UTC
+++ lib/pci.h
@@ -10,11 +10,11 @@
 #define _PCI_LIB_H
 
 #ifndef PCI_CONFIG_H
-#include "config.h"
+#include "pci/config.h"
 #endif
 
-#include "header.h"
-#include "types.h"
+#include "pci/header.h"
+#include "pci/types.h"
 
 #define PCI_LIB_VERSION 0x030604
 
