--- src/c4/std/vector_fwd.hpp.orig	2025-04-10 19:49:39 UTC
+++ src/c4/std/vector_fwd.hpp
@@ -14,7 +14,6 @@ namespace std {
 __pragma(warning(disable : 4643))
 #endif
 namespace std {
-template<typename> class allocator;
 #ifdef _GLIBCXX_DEBUG
 inline namespace __debug {
 template<typename T, typename Alloc> class vector;
@@ -29,7 +28,6 @@ inline namespace _LIBCPP_ABI_NAMESPACE {
 #elif defined(_LIBCPP_ABI_NAMESPACE)
 namespace std {
 inline namespace _LIBCPP_ABI_NAMESPACE {
-template<typename> class allocator;
 template<typename T, typename Alloc> class vector;
 } // namespace _LIBCPP_ABI_NAMESPACE
 } // namespace std
