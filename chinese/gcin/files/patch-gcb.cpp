--- gcb.cpp.orig	2015-11-22 23:15:12 UTC
+++ gcb.cpp
@@ -1,3 +1,4 @@
+#if USE_GCB
 #include <stdlib.h>
 #include "os-dep.h"
 #include <gtk/gtk.h>
@@ -6,6 +7,7 @@
 #include "gcin.h"
 #include "gcin-conf.h"
 
+void free_gcb();
 static GtkWidget *mainwin;
 static GtkClipboard *pclipboard_clipboard, *pclipboard_primary;
 static GtkWidget **buttonArr;
@@ -529,4 +531,4 @@ void free_gcb() {
   g_free(buttonStr); buttonStr = NULL;
   }
 }
-
+#endif
