--- src/core/include/function_templates.h.orig	2022-02-21 19:44:45 UTC
+++ src/core/include/function_templates.h
@@ -156,7 +156,6 @@ void ArrayForEach(ARG_TYPE *array, unsigned long dimen
 template <typename ARG_TYPE>
 void InitializeArray(ARG_TYPE *array, unsigned long dimension,
                      ARG_TYPE &&value) {
-  #pragma clang loop unroll_count(8)
   #pragma GCC unroll 4
   for (unsigned long i = 0UL; i < dimension; i++) {
     array[i] = value;
