--- lib/database/src/so/engines/SoCalcParse.y.old	Sun Aug  3 14:03:28 2003
+++ lib/database/src/so/engines/SoCalcParse.y	Sun Aug  3 14:09:13 2003
@@ -20,10 +20,14 @@
 #include <Inventor/errors/SoDebugError.h>
 #include "SoCalcExpr.h"
 #include <stdio.h>
+
 #ifdef __APPLE__
 #include <float.h>
 #include <limits.h>
-#else
+#elif defined __FreeBSD__
+#include <float.h>
+#define MINFLOAT FLT_MIN
+#else // __FreeBSD__
 #include <values.h>
 #endif
 #include <math.h>
