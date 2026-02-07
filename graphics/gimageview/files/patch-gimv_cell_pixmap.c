--- src/gimv_cell_pixmap.c.orig	2009-01-11 13:18:44.000000000 -0500
+++ src/gimv_cell_pixmap.c	2009-01-11 13:18:52.000000000 -0500
@@ -25,10 +25,6 @@
  *  Copyright (C) 2000  Red Hat, Inc.,  Jonathan Blandford <jrb@redhat.com>
  */
 
-#ifndef GTK_DISABLE_DEPRECATED
-#  define GTK_DISABLE_DEPRECATED
-#endif /* GTK_DISABLE_DEPRECATED */
-
 #include "gimv_cell_pixmap.h"
 
 #if (GTK_MAJOR_VERSION >= 2)
