--- lib/testm.c.orig	Fri Jul 20 14:02:56 2001
+++ lib/testm.c	Wed Jan 26 15:35:47 2005
@@ -16,10 +16,17 @@
 # define __USE_BSD 1
 # define __USE_XOPEN 1
 # define __USE_SVID 1
-#include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
+
+#define	M_LOG2E		1.4426950408889634074	/* log 2e */
+#define	M_LOG10E	0.43429448190325182765	/* log 10e */
+#define	M_LN2		0.69314718055994530942	/* log e2 */
+#define	M_LN10		2.30258509299404568402	/* log e10 */
+#define	M_E		2.7182818284590452354	/* e */
+#define	M_PI		3.14159265358979323846	/* pi */
+#define	HUGE_VAL	__builtin_huge_val()
 
 #ifndef NAN
 #define NAN (0./0.)
