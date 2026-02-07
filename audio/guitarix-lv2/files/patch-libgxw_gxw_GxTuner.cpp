https://sourceforge.net/p/guitarix/bugs/98/

--- libgxw/gxw/GxTuner.cpp.orig	2020-05-28 17:40:55 UTC
+++ libgxw/gxw/GxTuner.cpp
@@ -18,6 +18,7 @@
 
 #include "GxTuner.h"
 #include <math.h>
+#include <cmath>
 
 #define P_(s) (s)   // FIXME -> gettext
 
