--- src/cpp_common/get_check_data.cpp.orig	2024-02-09 00:36:37 UTC
+++ src/cpp_common/get_check_data.cpp
@@ -262,7 +262,7 @@ int64_t*
  * @returns The resultant array
  */
 int64_t*
-get_array(ArrayType *v, size_t *arrlen, bool allow_empty) {
+get_array(ArrayType *v, uint64_t *arrlen, bool allow_empty) {
     int64_t *c_array = nullptr;
 
     auto    element_type = ARR_ELEMTYPE(v);
