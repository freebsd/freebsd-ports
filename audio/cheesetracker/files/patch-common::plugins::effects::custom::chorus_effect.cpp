--- common/plugins/effects/custom/chorus_effect.cpp.orig	Fri Apr 23 05:21:14 2004
+++ common/plugins/effects/custom/chorus_effect.cpp	Tue Mar 27 20:51:01 2007
@@ -10,7 +10,7 @@
 //
 //
 #include "chorus_effect.h"
-
+#include <math.h>
 
 #define MIX_CALCULATE_INCREMENT_INTERVAL 8
 
