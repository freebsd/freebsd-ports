--- libgthumb/image-viewer.c.orig	Sun Aug 18 00:36:59 2002
+++ libgthumb/image-viewer.c	Sun Aug 18 00:37:08 2002
@@ -21,6 +21,7 @@
  */
 
 #include <math.h>
+#include <sys/types.h>
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtkadjustment.h>
 #include <gtk/gtkhscrollbar.h>
