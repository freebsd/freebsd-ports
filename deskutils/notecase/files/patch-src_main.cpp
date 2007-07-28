--- src/main.cpp.orig	Thu Jul 19 16:58:40 2007
+++ src/main.cpp	Thu Jul 19 16:58:55 2007
@@ -11,6 +11,8 @@
 #include <gtk/gtk.h>
 #include <libintl.h>
 
+#include <libgen.h>
+
 #include "interface.h"
 #include "callbacks.h"
 #include "support.h"
