--- data/tux/ModuleTux.cpp.orig	Thu Nov 20 17:46:17 2003
+++ data/tux/ModuleTux.cpp	Fri Dec 12 21:30:15 2003
@@ -7,6 +7,7 @@
  ***************************************************************************/
 
 #include "Private.h"
+#include "Config.h"
 #include "Behavior.h"
 #include "Group.h"
 #include "Pinball.h"
@@ -15,7 +16,6 @@
 #include "Score.h"
 #include "Keyboard.h"
 #include "Table.h"
-#include "Config.h"
 
 #define MISSION_TEXT_TIMEOUT 6000
 #define INFO_TEXT_TIME 600
