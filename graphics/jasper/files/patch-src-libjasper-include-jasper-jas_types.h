$FreeBSD$

--- src/libjasper/include/jasper/jas_types.h	Sat Oct  4 12:57:58 2003
+++ src/libjasper/include/jasper/jas_types.h	Wed Dec 17 10:29:46 2003
@@ -223,13 +223,13 @@
 #endif
 /**********/
 #if !defined(INT_FAST64_MIN)
-typedef longlong int_fast64_t;
+typedef long long int_fast64_t;
 #define INT_FAST64_MIN	LLONG_MIN
 #define INT_FAST64_MAX	LLONG_MAX
 #endif
 /**********/
 #if !defined(UINT_FAST64_MAX)
-typedef ulonglong uint_fast64_t;
+typedef unsigned long long uint_fast64_t;
 #define UINT_FAST64_MAX	ULLONG_MAX
 #endif
 /**********/
