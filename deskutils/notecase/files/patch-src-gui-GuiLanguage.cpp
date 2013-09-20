--- src/gui/GuiLanguage.cpp.orig	2013-09-18 16:02:26.000000000 +0200
+++ src/gui/GuiLanguage.cpp	2013-09-18 16:03:53.000000000 +0200
@@ -17,6 +17,7 @@
 #ifdef ENABLE_NLS
 #include <libintl.h>
 #endif
+#include <stdlib.h>
 #include <string.h>
 
 #include "../lib/EnumDirectory.h"
