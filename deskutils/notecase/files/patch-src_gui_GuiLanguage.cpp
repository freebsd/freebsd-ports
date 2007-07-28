--- src/gui/GuiLanguage.cpp.orig	Wed Jun  6 15:38:20 2007
+++ src/gui/GuiLanguage.cpp	Thu Jul 19 17:19:33 2007
@@ -13,6 +13,7 @@
 #include "GuiLanguage.h"
 #include <algorithm>
 #include <gtk/gtk.h>
+#include <libgen.h>
 #ifdef ENABLE_NLS
 #include <libintl.h>
 #endif
