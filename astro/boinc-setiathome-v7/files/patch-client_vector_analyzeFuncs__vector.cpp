--- client/vector/analyzeFuncs_vector.cpp.orig	2011-08-04 00:35:40 UTC
+++ client/vector/analyzeFuncs_vector.cpp
@@ -98,9 +98,7 @@
 
 
 #ifndef __APPLE_CC__
-#ifdef HAVE___ISNAN
-#define isnotnan(x) (!__isnan(x))
-#elif defined(HAVE__ISNAN)
+#if defined(HAVE__ISNAN)
 #define isnotnan(x) (!_isnan(x))
 #elif defined(HAVE_ISNAN)
 #define isnotnan(x) (!isnan(x))
