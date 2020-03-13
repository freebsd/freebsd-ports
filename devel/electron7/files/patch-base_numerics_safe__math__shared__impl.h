--- base/numerics/safe_math_shared_impl.h.orig	2019-12-12 12:38:59 UTC
+++ base/numerics/safe_math_shared_impl.h
@@ -23,8 +23,7 @@
 // Where available use builtin math overflow support on Clang and GCC.
 #elif !defined(__native_client__) &&                         \
       ((defined(__clang__) &&                                \
-        ((__clang_major__ > 3) ||                            \
-         (__clang_major__ == 3 && __clang_minor__ >= 4))) || \
+        (__clang_major__ > 6)) ||                            \
        (defined(__GNUC__) && __GNUC__ >= 5))
 #include "base/numerics/safe_math_clang_gcc_impl.h"
 #define BASE_HAS_OPTIMIZED_SAFE_MATH (1)
