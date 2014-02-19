--- src/ui/gtk/plotter.cc.orig	2010-03-07 20:50:22.000000000 +0100
+++ src/ui/gtk/plotter.cc	2013-12-15 14:50:48.000000000 +0100
@@ -18,8 +18,7 @@
  */
 
 #include <cairo/cairo.h>
-#include <glib-2.0/glib/gmain.h>
-#include <gtk-2.0/gtk/gtkspinbutton.h>
+#include <glib.h>
 
 #include "kc/kc.h"
 #include "kc/system.h"
