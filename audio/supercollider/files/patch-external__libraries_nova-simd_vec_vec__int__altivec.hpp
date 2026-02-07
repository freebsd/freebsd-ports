--- external_libraries/nova-simd/vec/vec_int_altivec.hpp.orig	2025-07-26 19:07:55 UTC
+++ external_libraries/nova-simd/vec/vec_int_altivec.hpp
@@ -35,7 +35,7 @@ struct int_vec_altivec (private)
     static ivec set_vector(int i)
     {
 #ifdef __GNUC__
-        return (ivec){i, i, i, i};
+        return (ivec){static_cast<unsigned int>(i), static_cast<unsigned int>(i), static_cast<unsigned int>(i), static_cast<unsigned int>(i)};
 #else
 #error compiler not supported
 #endif
