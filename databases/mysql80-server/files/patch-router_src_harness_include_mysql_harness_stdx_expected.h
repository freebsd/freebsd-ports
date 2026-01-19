--- router/src/harness/include/mysql/harness/stdx/expected.h.orig	2025-09-24 11:00:44 UTC
+++ router/src/harness/include/mysql/harness/stdx/expected.h
@@ -55,26 +55,6 @@
   };
 #endif
 
-/* workaround default-constructor of std::unique_ptr<T, D> triggering a
- * static-exception when it is tested for "std::is_default_constructible"
- *
- * The problem exists in GCC's libstdc++ up to 7.0.0 and is tracked by C++ std
- * as DR 2801
- *
- *   http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#2801
- *
- * It is fixed in GCC-7.1.0 and later:
- *
- * https://gcc.gnu.org/legacy-ml/gcc-cvs/2017-01/msg00068.html
- */
-
-#include <memory>
-namespace std {
-template <class T>
-struct is_default_constructible<std::unique_ptr<T, void (*)(T *)>>
-    : std::false_type {};
-}  // namespace std
-
 namespace stdx {
 
 // inplace construction of unexpected values.
