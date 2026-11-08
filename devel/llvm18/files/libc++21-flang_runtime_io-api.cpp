--- flang/runtime/io-api.cpp.orig
+++ flang/runtime/io-api.cpp
@@ -1496,7 +1496,7 @@
 // Provide own definition for `std::__libcpp_verbose_abort` to avoid dependency
 // on the version provided by libc++.
 
-void std::__libcpp_verbose_abort(char const *format, ...) {
+void std::__libcpp_verbose_abort(char const *format, ...) _NOEXCEPT {
   va_list list;
   va_start(list, format);
   std::vfprintf(stderr, format, list);
