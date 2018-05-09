--- modules/highgui/src/window_gtk.cpp.orig	2016-12-23 12:54:44 UTC
+++ modules/highgui/src/window_gtk.cpp
@@ -46,10 +46,12 @@
 
 #if defined (HAVE_GTK)
 
+#include <stdio.h>
+#include <stdlib.h>
 #include <gtk/gtk.h>
+#include <gdk/gdk.h>
 #include <gdk/gdkkeysyms.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
-#include <stdio.h>
 
 #if (GTK_MAJOR_VERSION == 3)
   #define GTK_VERSION3 1
