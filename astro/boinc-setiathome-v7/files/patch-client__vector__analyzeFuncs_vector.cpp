--- client/vector/analyzeFuncs_vector.cpp.orig	2013-07-11 22:32:37.000000000 +0200
+++ client/vector/analyzeFuncs_vector.cpp	2013-07-11 22:41:59.000000000 +0200
@@ -98,9 +98,7 @@
 
 
 #ifndef __APPLE_CC__
-#ifdef HAVE___ISNAN
-#define isnotnan(x) (!__isnan(x))
-#elif defined(HAVE__ISNAN)
+#if defined(HAVE__ISNAN)
 #define isnotnan(x) (!_isnan(x))
 #elif defined(HAVE_ISNAN)
 #define isnotnan(x) (!isnan(x))
