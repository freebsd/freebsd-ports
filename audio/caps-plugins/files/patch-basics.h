--- basics.h.orig	2016-09-11 06:12:08 UTC
+++ basics.h
@@ -38,6 +38,7 @@
 #define _ISOC99_SOURCE 1
 #define _ISOC9X_SOURCE 1
 
+#include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -49,14 +50,14 @@
 
 #include "ladspa.h"
 
-typedef __int8_t			int8;
-typedef __uint8_t			uint8;
-typedef __int16_t			int16;
-typedef __uint16_t		uint16;
-typedef __int32_t			int32;
-typedef __uint32_t		uint32;
-typedef __int64_t			int64;
-typedef __uint64_t		uint64;
+typedef int8_t			int8;
+typedef uint8_t			uint8;
+typedef int16_t			int16;
+typedef uint16_t		uint16;
+typedef int32_t			int32;
+typedef uint32_t		uint32;
+typedef int64_t			int64;
+typedef uint64_t		uint64;
 
 #define MIN_GAIN 1e-6 /* -120 dB */
 /* smallest non-denormal 32 bit IEEE float is 1.18e-38 */
@@ -124,7 +125,7 @@ T clamp (T value, T lower, T upper)
 	return value;
 }
 
-static inline float frandom() { return (float) random() / (float) RAND_MAX; }
+static inline float frandom() { return (float) rand() / (float) RAND_MAX; }
 
 /* NB: also true if 0  */
 inline bool 
