--- src/view.c.orig	Sat Aug 10 02:25:18 2002
+++ src/view.c	Tue Oct 26 17:04:03 2004
@@ -22,8 +22,13 @@
 #include <unistd.h>
 #include <math.h>
 #include <string.h>
-#include "giram.h"
+
+#undef GTK_DISABLE_DEPRECATED
+#warning GTK_DISABLE_DEPRECATED
+
 #include <gdk/gdkkeysyms.h>
+#include <gtk/gtkitemfactory.h>
+#include "giram.h"
 
 #include "tools/tools.h"
 #include "tools/tool_select.h"
