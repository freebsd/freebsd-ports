--- src/classes/dotImporter.cc.orig	2003-03-20 07:37:55 UTC
+++ src/classes/dotImporter.cc
@@ -1,5 +1,6 @@
 #include "dotImporter.h"
-#include <string.h>
+#include <cstdlib>
+#include <cstring>
 #include <gtk/gtk.h>
 #include "../interface.h"
 
