--- src/libjasper/include/jasper/jas_types.h.orig	Tue Jan 15 17:07:34 2002
+++ src/libjasper/include/jasper/jas_types.h	Fri Sep  6 07:22:09 2002
@@ -204,7 +204,7 @@
 #endif
 /**********/
 #if !defined(UINT_FAST8_MIN)
-typedef uchar uint_fast8_t;
+typedef unsigned char uint_fast8_t;
 #define UINT_FAST8_MIN	0
 #define UINT_FAST8_MAX	255
 #endif
@@ -216,7 +216,7 @@
 #endif
 /**********/
 #if !defined(UINT_FAST16_MIN)
-typedef ushort uint_fast16_t;
+typedef unsigned short uint_fast16_t;
 #define UINT_FAST16_MIN	USHRT_MIN
 #define UINT_FAST16_MAX	USHRT_MAX
 #endif
@@ -228,19 +228,19 @@
 #endif
 /**********/
 #if !defined(UINT_FAST32_MIN)
-typedef uint uint_fast32_t;
+typedef unsigned int uint_fast32_t;
 #define UINT_FAST32_MIN	UINT_MIN
 #define UINT_FAST32_MAX	UINT_MAX
 #endif
 /**********/
 #if !defined(INT_FAST64_MIN)
-typedef longlong int_fast64_t;
+typedef long long int_fast64_t;
 #define INT_FAST64_MIN	LLONG_MIN
 #define INT_FAST64_MAX	LLONG_MAX
 #endif
 /**********/
 #if !defined(UINT_FAST64_MIN)
-typedef ulonglong uint_fast64_t;
+typedef unsigned long long uint_fast64_t;
 #define UINT_FAST64_MIN	ULLONG_MIN
 #define UINT_FAST64_MAX	ULLONG_MAX
 #endif
