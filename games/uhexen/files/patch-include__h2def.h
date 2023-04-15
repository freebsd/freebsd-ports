--- include/h2def.h.orig	2001-12-02 08:51:54 UTC
+++ include/h2def.h
@@ -26,7 +26,11 @@
 
 /* XXX ifdefs */
 
+#ifndef __FreeBSD__
 typedef unsigned int uint;
+#else
+#include <sys/types.h>
+#endif
 
 // Uncomment, to enable all timebomb stuff
 //#define TIMEBOMB
@@ -894,10 +898,8 @@ fixed_t	FixedDiv2 (fixed_t a, fixed_t b);
 #endif
 
 #ifdef __BIG_ENDIAN__
-short ShortSwap(short);
-long LongSwap(long);
-#define SHORT(x)	ShortSwap(x)
-#define LONG(x)		LongSwap(x)
+#define SHORT(x)	__builtin_bswap16(x)
+#define LONG(x)		__builtin_bswap32(x)
 #else
 #define SHORT(x)	(x)
 #define LONG(x)		(x)
