--- ./client/vector/analyzeFuncs_vector.cpp.orig	2009-07-14 21:02:10.000000000 +0200
+++ ./client/vector/analyzeFuncs_vector.cpp	2013-09-23 19:16:42.000000000 +0200
@@ -86,13 +86,12 @@
 #include <sys/sysctl.h>
 #endif
 
+using namespace std;
 
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
