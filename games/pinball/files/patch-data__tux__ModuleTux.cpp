--- data/tux/ModuleTux.cpp.orig	2018-03-24 23:40:31 UTC
+++ data/tux/ModuleTux.cpp
@@ -7,6 +7,7 @@
  ***************************************************************************/
 
 #include "Private.h"
+#include "Config.h"
 #include "Behavior.h"
 #include "Group.h"
 #include "Pinball.h"
@@ -15,7 +16,7 @@
 #include "Score.h"
 #include "Keyboard.h"
 #include "Table.h"
-#include "Config.h"
+#include <libintl.h>
 
 #include <locale>
 
