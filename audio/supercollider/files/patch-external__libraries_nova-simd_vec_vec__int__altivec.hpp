--- external_libraries/nova-simd/vec/vec_int_altivec.hpp.orig	2020-09-03 23:55:08.848538000 +0200
+++ external_libraries/nova-simd/vec/vec_int_altivec.hpp	2020-09-03 23:58:16.614642000 +0200
@@ -35,7 +35,7 @@
     static ivec set_vector(int i)
     {
 #ifdef __GNUC__
-        return (ivec){i, i, i, i};
+        return (ivec){static_cast<unsigned int>(i), static_cast<unsigned int>(i), static_cast<unsigned int>(i), static_cast<unsigned int>(i)};
 #else
 #error compiler not supported
 #endif
