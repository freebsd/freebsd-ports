--- src/awgn.c.orig	Sun Nov 19 09:07:24 2006
+++ src/awgn.c	Fri Jul 20 11:59:50 2007
@@ -48,12 +48,8 @@
 
 #include <stdlib.h>
 #include <inttypes.h>
-#if defined(HAVE_TGMATH_H)
 #include <tgmath.h>
-#endif
-#if defined(HAVE_MATH_H)
 #include <math.h>
-#endif
 
 #include "spandsp/telephony.h"
 #include "spandsp/dc_restore.h"
