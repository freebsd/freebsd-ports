--- boost/static_assert.hpp.orig	2013-09-21 20:17:00 UTC
+++ boost/static_assert.hpp
@@ -67,7 +67,7 @@
 //
 // If the compiler warns about unused typedefs then enable this:
 //
-#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)))
+#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7))) || defined(__clang__)
 #  define BOOST_STATIC_ASSERT_UNUSED_ATTRIBUTE __attribute__((unused))
 #else
 #  define BOOST_STATIC_ASSERT_UNUSED_ATTRIBUTE
