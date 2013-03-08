--- opensync/opensync_list.c.orig	2013-02-05 21:45:11.000000000 +0000
+++ opensync/opensync_list.c	2013-02-05 21:45:22.000000000 +0000
@@ -30,7 +30,7 @@
  * MT safe
  */
 
-#include <glib/gmem.h>
+#include <glib.h>
 #include "opensync_list.h"
 #include "opensync_internals.h"
 
