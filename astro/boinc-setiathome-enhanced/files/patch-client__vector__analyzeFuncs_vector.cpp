--- client/vector/analyzeFuncs_vector.cpp.orig	2009-07-14 21:02:10.000000000 +0200
+++ client/vector/analyzeFuncs_vector.cpp	2011-02-27 15:56:58.000000000 +0100
@@ -87,12 +87,10 @@
 #endif
 
 
-#ifdef HAVE___ISNAN
-#define isnotnan(x) (!__isnan(x))
-#elif defined(HAVE__ISNAN)
+#if defined(HAVE__ISNAN)
 #define isnotnan(x) (!_isnan(x))
 #elif defined(HAVE_ISNAN)
-#define isnotnam(x) (!isnan(x))
+#define isnotnan(x) (!isnan(x))
 #else
 #define isnotnan(x) ((x) == (x))
 #endif
