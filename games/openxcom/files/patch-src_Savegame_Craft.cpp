--- src/Savegame/Craft.cpp.orig	2019-08-03 22:32:11 UTC
+++ src/Savegame/Craft.cpp
@@ -18,6 +18,7 @@
  */
 #define _USE_MATH_DEFINES
 #include "Craft.h"
+#include <algorithm>
 #include <cmath>
 #include <sstream>
 #include "../Engine/Language.h"
