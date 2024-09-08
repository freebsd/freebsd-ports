--- rapidfuzz/distance.hpp.orig	2024-07-02 14:50:14 UTC
+++ rapidfuzz/distance.hpp
@@ -16,13 +16,13 @@ template <typename CharT, typename InputIt1, typename 
 namespace rapidfuzz {
 
 template <typename CharT, typename InputIt1, typename InputIt2>
-std::basic_string<CharT> editops_apply(const Editops& ops, InputIt1 first1, InputIt1 last1, InputIt2 first2,
-                                       InputIt2 last2)
+std::vector<CharT> editops_apply(const Editops& ops, InputIt1 first1, InputIt1 last1, InputIt2 first2,
+                                 InputIt2 last2)
 {
     auto len1 = static_cast<size_t>(std::distance(first1, last1));
     auto len2 = static_cast<size_t>(std::distance(first2, last2));
 
-    std::basic_string<CharT> res_str;
+    std::vector<CharT> res_str;
     res_str.resize(len1 + len2);
     size_t src_pos = 0;
     size_t dest_pos = 0;
@@ -62,20 +62,20 @@ template <typename CharT, typename Sentence1, typename
 }
 
 template <typename CharT, typename Sentence1, typename Sentence2>
-std::basic_string<CharT> editops_apply(const Editops& ops, const Sentence1& s1, const Sentence2& s2)
+std::vector<CharT> editops_apply(const Editops& ops, const Sentence1& s1, const Sentence2& s2)
 {
     return editops_apply<CharT>(ops, detail::to_begin(s1), detail::to_end(s1), detail::to_begin(s2),
                                 detail::to_end(s2));
 }
 
 template <typename CharT, typename InputIt1, typename InputIt2>
-std::basic_string<CharT> opcodes_apply(const Opcodes& ops, InputIt1 first1, InputIt1 last1, InputIt2 first2,
-                                       InputIt2 last2)
+std::vector<CharT> opcodes_apply(const Opcodes& ops, InputIt1 first1, InputIt1 last1, InputIt2 first2,
+                                 InputIt2 last2)
 {
     auto len1 = static_cast<size_t>(std::distance(first1, last1));
     auto len2 = static_cast<size_t>(std::distance(first2, last2));
 
-    std::basic_string<CharT> res_str;
+    std::vector<CharT> res_str;
     res_str.resize(len1 + len2);
     size_t dest_pos = 0;
 
@@ -101,7 +101,7 @@ template <typename CharT, typename Sentence1, typename
 }
 
 template <typename CharT, typename Sentence1, typename Sentence2>
-std::basic_string<CharT> opcodes_apply(const Opcodes& ops, const Sentence1& s1, const Sentence2& s2)
+std::vector<CharT> opcodes_apply(const Opcodes& ops, const Sentence1& s1, const Sentence2& s2)
 {
     return opcodes_apply<CharT>(ops, detail::to_begin(s1), detail::to_end(s1), detail::to_begin(s2),
                                 detail::to_end(s2));
