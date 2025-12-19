Suppress warnings when -pedantic is passed and using std < c++20, which could
also be errors if -Werror is also passed as is the case with www/dooble.

error: use of the 'nodiscard' attribute is a C++20 extension

https://github.com/llvm/llvm-project/issues/32865

--- src/corelib/global/qcompilerdetection.h.orig	2025-05-14 09:43:58 UTC
+++ src/corelib/global/qcompilerdetection.h
@@ -972,7 +972,7 @@
 #  define Q_REQUIRED_RESULT [[nodiscard]]
 #endif
 
-#if (defined(__cplusplus) && __has_cpp_attribute(nodiscard) >= 201907L /* used for both P1771 and P1301... */) \
+#if (defined(__cplusplus) && __has_cpp_attribute(nodiscard) >= 201907L && (!defined(Q_CC_CLANG) || __cplusplus >= 201907L) /* used for both P1771 and P1301... */) \
     || (!defined(__cplusplus) && __has_c_attribute(nodiscard) /* N2448 */)
 // [[nodiscard]] constructor (P1771)
 #  ifndef Q_NODISCARD_CTOR
