--- base/containers/checked_iterators.h.orig	2023-08-12 07:07:10 UTC
+++ base/containers/checked_iterators.h
@@ -24,6 +24,9 @@ class CheckedContiguousIterator {
   using pointer = T*;
   using reference = T&;
   using iterator_category = std::random_access_iterator_tag;
+#if __cplusplus >= 202002L
+  using iterator_concept = std::contiguous_iterator_tag;
+#endif
 
   // Required for converting constructor below.
   template <typename U>
@@ -31,10 +34,8 @@ class CheckedContiguousIterator {
 
   // Required for certain libc++ algorithm optimizations that are not available
   // for NaCl.
-#if defined(_LIBCPP_VERSION) && !BUILDFLAG(IS_NACL)
   template <typename Ptr>
   friend struct std::pointer_traits;
-#endif
 
   constexpr CheckedContiguousIterator() = default;
 
@@ -224,7 +225,6 @@ using CheckedContiguousConstIterator = CheckedContiguo
 
 }  // namespace base
 
-#if defined(_LIBCPP_VERSION) && !BUILDFLAG(IS_NACL)
 // Specialize both std::__is_cpp17_contiguous_iterator and std::pointer_traits
 // for CCI in case we compile with libc++ outside of NaCl. The former is
 // required to enable certain algorithm optimizations (e.g. std::copy can be a
@@ -242,13 +242,35 @@ using CheckedContiguousConstIterator = CheckedContiguo
 // [1] https://wg21.link/iterator.concept.contiguous
 // [2] https://wg21.link/std.iterator.tags
 // [3] https://wg21.link/pointer.traits.optmem
-namespace std {
 
+#if defined(_LIBCPP_VERSION)
+
+// TODO(crbug.com/1284275): Remove when C++20 is on by default, as the use
+// of `iterator_concept` above should suffice.
+_LIBCPP_BEGIN_NAMESPACE_STD
+
+// TODO(crbug.com/1449299): https://reviews.llvm.org/D150801 renamed this from
+// `__is_cpp17_contiguous_iterator` to `__libcpp_is_contiguous_iterator`. Clean
+// up the old spelling after libc++ rolls.
 template <typename T>
+struct __is_cpp17_contiguous_iterator;
+template <typename T>
 struct __is_cpp17_contiguous_iterator<::base::CheckedContiguousIterator<T>>
     : true_type {};
 
 template <typename T>
+struct __libcpp_is_contiguous_iterator;
+template <typename T>
+struct __libcpp_is_contiguous_iterator<::base::CheckedContiguousIterator<T>>
+    : true_type {};
+
+_LIBCPP_END_NAMESPACE_STD
+
+#endif
+
+namespace std {
+
+template <typename T>
 struct pointer_traits<::base::CheckedContiguousIterator<T>> {
   using pointer = ::base::CheckedContiguousIterator<T>;
   using element_type = T;
@@ -267,6 +289,5 @@ struct pointer_traits<::base::CheckedContiguousIterato
 };
 
 }  // namespace std
-#endif
 
 #endif  // BASE_CONTAINERS_CHECKED_ITERATORS_H_
