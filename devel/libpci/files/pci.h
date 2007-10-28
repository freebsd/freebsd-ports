--- lib/pci.h.orig	Thu Oct 30 15:57:58 2003
+++ lib/pci.h	Thu Oct 30 16:04:23 2003
@@ -9,9 +9,9 @@
 #ifndef _PCI_LIB_H
 #define _PCI_LIB_H
 
-#include "config.h"
-#include "header.h"
-#include "types.h"
+#include <pci/config.h>
+#include <pci/header.h>
+#include <pci/types.h>
 
 #define PCI_LIB_VERSION 0x020204
 
