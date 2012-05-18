--- document.c.orig    2012-03-25 00:57:24.000000000 +0400
+++ document.c 2012-04-23 15:02:51.000000000 +0400
@@ -12,6 +12,7 @@
 #include <errno.h>
 #include <glib.h>
 #include <glib/gi18n.h>
+#include <sys/wait.h>

 #include "document.h"
 #include "utils.h"
