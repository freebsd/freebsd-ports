--- src/v17tx.c.orig	Sun Mar 18 05:43:50 2007
+++ src/v17tx.c	Fri Jul 20 12:05:16 2007
@@ -35,12 +35,8 @@
 #include <inttypes.h>
 #include <stdlib.h>
 #include <string.h>
-#if defined(HAVE_TGMATH_H)
 #include <tgmath.h>
-#endif
-#if defined(HAVE_MATH_H)
 #include <math.h>
-#endif
 
 #include "spandsp/telephony.h"
 #include "spandsp/logging.h"
