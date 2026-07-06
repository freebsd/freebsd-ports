--- boost/charconv/detail/config.hpp.orig	2025-08-06 18:49:08 UTC
+++ boost/charconv/detail/config.hpp
@@ -197,6 +197,8 @@
 
 #define BOOST_CHARCONV_LDBL_IS_FLOAT128
 #define BOOST_CHARCONV_UNSUPPORTED_LONG_DOUBLE
+#if defined(__GNUC__) && !defined(__clang__)
 static_assert(std::is_same<long double, __float128>::value, "__float128 should be an alias to long double. Please open an issue at: https://github.com/boostorg/charconv");
+#endif
 
 #endif
