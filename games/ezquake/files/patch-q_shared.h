--- q_shared.h.orig	Tue Dec  5 22:01:04 2006
+++ q_shared.h	Tue Dec 19 19:45:32 2006
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <assert.h>
+#include <machine/endian.h>
 
 #include "mathlib.h"
 #include "sys.h"
@@ -114,21 +115,21 @@
 float	FloatSwapPDP2Big (float f);
 float	FloatSwapPDP2Lit (float f);
 
-#ifdef __BIG_ENDIAN__Q__
+#if BYTE_ORDER == BIG_ENDIAN
 #define BigShort(x)		(x)
 #define BigLong(x)		(x)
 #define BigFloat(x)		(x)
 #define LittleShort(x)	ShortSwap(x)
 #define LittleLong(x)	LongSwap(x)
 #define LittleFloat(x)	FloatSwap(x)
-#elif defined(__LITTLE_ENDIAN__Q__)
+#elif BYTE_ORDER == LITTLE_ENDIAN
 #define BigShort(x)		ShortSwap(x)
 #define BigLong(x)		LongSwap(x)
 #define BigFloat(x)		FloatSwap(x)
 #define LittleShort(x)	(x)
 #define LittleLong(x)	(x)
 #define LittleFloat(x)	(x)
-#elif defined(__PDP_ENDIAN__Q__)
+#elif BYTE_ORDER == PDP_ENDIAN
 #define BigShort(x)		ShortSwap(x)
 #define BigLong(x)		LongSwapPDP2Big(x)
 #define BigFloat(x)		FloatSwapPDP2Big(x)
