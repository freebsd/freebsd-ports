--- boost/config/compiler/clang.hpp.orig	2016-09-21 14:33:21 UTC
+++ boost/config/compiler/clang.hpp
@@ -110,6 +110,16 @@
 #  endif
 #endif
 
+//
+// Pick up _LIBCPP_VERSION definition if we are using libc++
+// If _LIBCPP_VERSION is not defined, then we will assume that
+// we are compiling on FreeBSD 9.x and using ancient libstdc++
+// from base gcc 4.2 with limited c++11 support.
+//
+#ifdef __cplusplus
+#  include <ciso646>
+#endif
+
 #if !__has_feature(cxx_auto_type)
 #  define BOOST_NO_CXX11_AUTO_DECLARATIONS
 #  define BOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
@@ -192,7 +202,13 @@
 #  define BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
 #endif
 
-#if !__has_feature(cxx_rvalue_references)
+// 
+// clang on FreeBSD 9.x uses libstdc++ from base GCC 4.2.1 which
+// does not support std::forward which this feature requires.
+// Assume that the lack of a _LIBCPP_VERSION definition indicates
+// that is our environment.
+//
+#if !__has_feature(cxx_rvalue_references) || !defined(_LIBCPP_VERSION)
 #  define BOOST_NO_CXX11_RVALUE_REFERENCES
 #endif
 
