--- src/exec/gbx_math.c.orig	Fri Oct 28 17:25:37 2005
+++ src/exec/gbx_math.c	Mon Nov  7 23:35:25 2005
@@ -27,6 +27,10 @@
 #include <math.h>
 #include <time.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__
+# include <mathl.h>
+# define modfl(a,b)	modf(a,b)
+#endif
 
 #include "gb_common.h"
 #include "gbx_math.h"
