--- src/backend/CSound_defs.h.orig	2004-06-18 10:45:47.000000000 +0800
+++ src/backend/CSound_defs.h	2012-07-06 14:10:05.000000000 +0800
@@ -50,6 +50,10 @@
 	#define MAX_LENGTH (0x7fffffffffffffffLL-(1024LL*1024LL))
 
 	#include <math.h>
+	extern "C" {
+		long double logl(long double);
+		long double expl(long double);
+	}
 	#define sample_fpos_floor(a)	(floorl(a))
 	#define sample_fpos_ceil(a)	(ceill(a))
 	#define sample_fpos_round(a)	(nearbyintl(a))
