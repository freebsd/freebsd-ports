--- logview/desc_db.c.orig	Wed Dec  1 16:45:13 2004
+++ logview/desc_db.c	Wed Dec  1 16:45:25 2004
@@ -21,6 +21,7 @@
 #include <gtk/gtk.h>
 #include <glib/gi18n.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include "logview.h"
 #include "desc_db.h"
