--- src/classes/optFileReader.cc.orig
+++ src/classes/optFileReader.cc
@@ -1,5 +1,6 @@
 #include "optFileReader.h"
-#include <string.h>
+#include <cstdlib>
+#include <cstring>
 #include <gtk/gtk.h>
 #include "../interface.h"
 
