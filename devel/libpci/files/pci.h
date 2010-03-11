--- lib/pci.h.orig	2009-07-04 13:11:04.000000000 -0300
+++ lib/pci.h	2010-03-08 19:46:36.000000000 -0300
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
 
 #define PCI_LIB_VERSION 0x030100
 
