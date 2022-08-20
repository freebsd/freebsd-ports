--- libreofficekit/qa/gtktiledviewer/gtv-lok-dialog.cxx.orig	2022-05-12 13:26:05 UTC
+++ libreofficekit/qa/gtktiledviewer/gtv-lok-dialog.cxx
@@ -10,7 +10,12 @@
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
+#include <cmath>
 #include <iostream>
+#include <sstream>
+#include <strstream>
+#include <string>
+#include <vector>
 
 #include <LibreOfficeKit/LibreOfficeKitGtk.h>
 #include <LibreOfficeKit/LibreOfficeKitEnums.h>
