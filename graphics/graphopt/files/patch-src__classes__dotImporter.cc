--- src/classes/dotImporter.cc.orig
+++ src/classes/dotImporter.cc
@@ -1,5 +1,6 @@
 #include "dotImporter.h"
-#include <string.h>
+#include <cstdlib>
+#include <cstring>
 #include <gtk/gtk.h>
 #include "../interface.h"
 
