--- libreofficekit/qa/gtktiledviewer/gtv-lok-dialog.cxx.orig	2020-05-06 18:00:34 UTC
+++ libreofficekit/qa/gtktiledviewer/gtv-lok-dialog.cxx
@@ -10,7 +10,12 @@
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
+#include <cmath>
 #include <iostream>
+#include <strstream>
+#include <sstream>
+#include <string>
+#include <vector>
 
 #include <LibreOfficeKit/LibreOfficeKitGtk.h>
 #include <LibreOfficeKit/LibreOfficeKitEnums.h>
