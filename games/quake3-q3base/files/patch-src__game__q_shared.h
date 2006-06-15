--- ./src/game/q_shared.h.orig	Wed Oct  5 19:51:28 2005
+++ ./src/game/q_shared.h	Thu Jun 15 12:03:49 2006
@@ -140,7 +140,9 @@
 int	LongSwap (int l);
 float	FloatSwap (const float *f);
 
-#if defined (__i386__) || defined (__MIPSEL__) || defined (__amd64__)
+#include <machine/endian.h>
+
+#if BYTE_ORDER == LITTLE_ENDIAN
 /* Little Endian */
 #define BigShort ShortSwap
 #define LittleShort
@@ -148,7 +150,7 @@
 #define LittleLong
 #define BigFloat(l) FloatSwap(&l)
 #define LittleFloat
-#elif defined (__mips__) || defined (__ppc__) || defined (__sparc__)
+#elif BYTE_ORDER == BIG_ENDIAN
 /* Big Endian */
 #define BigShort
 #define LittleShort ShortSwap
@@ -199,7 +201,7 @@
 #elif defined (__axp__)
 #define CPUSTRING	"alpha"
 #else
-#error	"Unknown processor family"
+#define CPUSTRING	"unknown"
 #endif
 
 /*
