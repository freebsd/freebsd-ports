--- external_libraries/nova-simd/vec/vec_int_altivec.hpp.orig
+++ external_libraries/nova-simd/vec/vec_int_altivec.hpp
@@ -35,7 +35,7 @@
     static ivec set_vector(int i)
     {
 #ifdef __GNUC__
-        return (ivec){i, i, i, i};
+        return (ivec){(unsigned)i, (unsigned)i, (unsigned)i, (unsigned)i};
 #else
 #error compiler not supported
 #endif
