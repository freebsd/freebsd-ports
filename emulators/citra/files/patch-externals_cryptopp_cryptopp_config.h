https://github.com/citra-emu/citra/issues/3435

--- externals/cryptopp/cryptopp/config.h.orig	2018-01-22 20:54:51 UTC
+++ externals/cryptopp/cryptopp/config.h
@@ -1027,7 +1027,7 @@ NAMESPACE_END
 #endif // alignof
 
 // lambdas: MS at VS2012 (17.00); GCC at 4.9; Clang at 3.3; Intel 12.0; SunCC 5.14.
-#if (CRYPTOPP_MSC_VERSION >= 1700) || __has_feature(cxx_lambda) || \
+#if (CRYPTOPP_MSC_VERSION >= 1700) || __has_feature(cxx_lambdas) || \
 	(__INTEL_COMPILER >= 1200) || (CRYPTOPP_GCC_VERSION >= 40900) || (__SUNPRO_CC >= 0x5140)
 #  define CRYPTOPP_CXX11_LAMBDA 1
 #endif // lambdas
