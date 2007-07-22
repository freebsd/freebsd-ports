--- src/tone_generate.c.orig	Sat Mar  3 05:40:33 2007
+++ src/tone_generate.c	Fri Jul 20 12:03:07 2007
@@ -37,12 +37,8 @@
 #include <stdio.h>
 #include <time.h>
 #include <fcntl.h>
-#if defined(HAVE_TGMATH_H)
 #include <tgmath.h>
-#endif
-#if defined(HAVE_MATH_H)
 #include <math.h>
-#endif
 
 #include "spandsp/telephony.h"
 #include "spandsp/dc_restore.h"
