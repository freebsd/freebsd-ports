--- lib/pci.h.orig	Thu Oct 30 15:57:58 2003
+++ lib/pci.h	Thu Oct 30 16:04:23 2003
@@ -11,8 +11,7 @@
 #ifndef _PCI_LIB_H
 #define _PCI_LIB_H
 
-#include "config.h"
-#include "header.h"
+#define OS_FREEBSD
 
 /*
  *	Types
