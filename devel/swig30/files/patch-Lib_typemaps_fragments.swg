--- Lib/typemaps/fragments.swg.orig	2016-09-10 23:27:20 UTC
+++ Lib/typemaps/fragments.swg
@@ -172,6 +172,7 @@
 # if defined(isfinite)
 #  define SWIG_isfinite(X) (isfinite(X))
 # elif defined __cplusplus && __cplusplus >= 201103L
+#  include <cmath>
 #  define SWIG_isfinite(X) (std::isfinite(X))
 # elif defined(_MSC_VER)
 #  define SWIG_isfinite(X) (_finite(X))
