https://github.com/boostorg/regex/issues/72

--- boost/regex/config.hpp.orig	2018-10-30 22:45:30 UTC
+++ boost/regex/config.hpp
@@ -117,7 +117,7 @@
  * Clang fails to export template instances with -fvisibility=hidden, see
  * https://github.com/boostorg/regex/issues/49
  */
-#ifdef __clang__
+#if defined(__clang__) || defined(_LIBCPP_VERSION)
 #  define BOOST_REGEX_NO_EXTERNAL_TEMPLATES
 #endif
 
