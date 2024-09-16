--- extern/rapidfuzz-cpp/rapidfuzz/details/SplittedSentenceView.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/details/SplittedSentenceView.hpp
@@ -34,7 +34,7 @@ class SplittedSentenceView { (public)
         return m_sentence.size();
     }
 
-    std::basic_string<CharT> join() const;
+    std::vector<CharT> join() const;
 
     const RangeVec<InputIt>& words() const
     {
@@ -68,19 +68,19 @@ template <typename InputIt>
 }
 
 template <typename InputIt>
-auto SplittedSentenceView<InputIt>::join() const -> std::basic_string<CharT>
+auto SplittedSentenceView<InputIt>::join() const -> std::vector<CharT>
 {
     if (m_sentence.empty()) {
-        return std::basic_string<CharT>();
+        return std::vector<CharT>();
     }
 
     auto sentence_iter = m_sentence.begin();
-    std::basic_string<CharT> joined(sentence_iter->begin(), sentence_iter->end());
-    const std::basic_string<CharT> whitespace{0x20};
+    std::vector<CharT> joined(sentence_iter->begin(), sentence_iter->end());
+    const std::vector<CharT> whitespace{0x20};
     ++sentence_iter;
     for (; sentence_iter != m_sentence.end(); ++sentence_iter) {
         joined.append(whitespace)
-            .append(std::basic_string<CharT>(sentence_iter->begin(), sentence_iter->end()));
+            .append(std::vector<CharT>(sentence_iter->begin(), sentence_iter->end()));
     }
     return joined;
 }
