--- boost/math/cstdfloat/cstdfloat_limits.hpp.orig	2023-12-06 21:03:04 UTC
+++ boost/math/cstdfloat/cstdfloat_limits.hpp
@@ -24,7 +24,7 @@
 #pragma GCC system_header
 #endif
 
-  #if defined(BOOST_CSTDFLOAT_HAS_INTERNAL_FLOAT128_T) && defined(BOOST_MATH_USE_FLOAT128) && !defined(BOOST_CSTDFLOAT_NO_LIBQUADMATH_SUPPORT) && (!defined(__GNUC__) || (defined(__GNUC__) && __GNUC__ < 14))
+  #if defined(BOOST_CSTDFLOAT_HAS_INTERNAL_FLOAT128_T) && defined(BOOST_MATH_USE_FLOAT128) && !defined(BOOST_CSTDFLOAT_NO_LIBQUADMATH_SUPPORT) && (!defined(_GLIBCXX_RELEASE) || (defined(_GLIBCXX_RELEASE) && _GLIBCXX_RELEASE < 14))
 
     #include <limits>
     #include <boost/math/tools/nothrow.hpp>
