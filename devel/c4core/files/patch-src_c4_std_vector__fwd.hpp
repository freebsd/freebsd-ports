--- src/c4/std/vector_fwd.hpp.orig	2022-01-06 01:17:58 UTC
+++ src/c4/std/vector_fwd.hpp
@@ -8,12 +8,10 @@
 // forward declarations for std::vector
 #if defined(__GLIBCXX__) || defined(__GLIBCPP__) || defined(_MSC_VER)
 namespace std {
-template<typename> class allocator;
 template<typename T, typename Alloc> class vector;
 } // namespace std
 #elif defined(_LIBCPP_VERSION)
 namespace std {
-template<typename> class allocator;
 #if defined(__EMSCRIPTEN__)
 inline namespace __2 {
 template<typename T, typename Alloc> class vector;
