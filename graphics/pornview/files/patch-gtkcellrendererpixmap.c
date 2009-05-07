--- src/support/widgets/gtkcellrendererpixmap.c.orig	2002-12-13 12:02:45.000000000 +0100
+++ src/support/widgets/gtkcellrendererpixmap.c	2009-04-19 17:20:36.000000000 +0200
@@ -12,9 +12,6 @@
  *  Copyright (C) 2000  Red Hat, Inc.,  Jonathan Blandford <jrb@redhat.com>
  */
 
-#ifndef GTK_DISABLE_DEPRECATED
-#define GTK_DISABLE_DEPRECATED
-#endif /* GTK_DISABLE_DEPRECATED */
 
 #include "gtkcellrendererpixmap.h"
 
@@ -59,10 +56,10 @@
     PROP_MASK_EXPANDER_CLOSED
 };
 
-GtkType
+GType
 gtk_cell_renderer_pixmap_get_type (void)
 {
-    static GtkType cell_pixmap_type = 0;
+    static GType cell_pixmap_type = 0;
 
     if (!cell_pixmap_type)
     {
