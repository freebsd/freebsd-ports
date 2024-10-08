--- extern/rapidfuzz-cpp/rapidfuzz/fuzz.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/fuzz.hpp
@@ -186,7 +186,7 @@ struct CachedPartialRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     rapidfuzz::detail::CharSet<CharT1> s1_char_set;
     CachedRatio<CharT1> cached_ratio;
 };
@@ -296,7 +296,7 @@ struct CachedTokenSortRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1_sorted;
+    std::vector<CharT1> s1_sorted;
     CachedRatio<CharT1> cached_ratio;
 };
 
@@ -354,7 +354,7 @@ struct CachedPartialTokenSortRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1_sorted;
+    std::vector<CharT1> s1_sorted;
     CachedPartialRatio<CharT1> cached_partial_ratio;
 };
 
@@ -422,8 +422,8 @@ struct CachedTokenSetRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
-    detail::SplittedSentenceView<typename std::basic_string<CharT1>::iterator> tokens_s1;
+    std::vector<CharT1> s1;
+    detail::SplittedSentenceView<typename std::vector<CharT1>::iterator> tokens_s1;
 };
 
 template <typename Sentence1>
@@ -479,8 +479,8 @@ struct CachedPartialTokenSetRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
-    detail::SplittedSentenceView<typename std::basic_string<CharT1>::iterator> tokens_s1;
+    std::vector<CharT1> s1;
+    detail::SplittedSentenceView<typename std::vector<CharT1>::iterator> tokens_s1;
 };
 
 template <typename Sentence1>
@@ -539,9 +539,9 @@ struct CachedTokenRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
-    detail::SplittedSentenceView<typename std::basic_string<CharT1>::iterator> s1_tokens;
-    std::basic_string<CharT1> s1_sorted;
+    std::vector<CharT1> s1;
+    detail::SplittedSentenceView<typename std::vector<CharT1>::iterator> s1_tokens;
+    std::vector<CharT1> s1_sorted;
     CachedRatio<CharT1> cached_ratio_s1_sorted;
 };
 
@@ -601,9 +601,9 @@ struct CachedPartialTokenRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
-    detail::SplittedSentenceView<typename std::basic_string<CharT1>::iterator> tokens_s1;
-    std::basic_string<CharT1> s1_sorted;
+    std::vector<CharT1> s1;
+    detail::SplittedSentenceView<typename std::vector<CharT1>::iterator> tokens_s1;
+    std::vector<CharT1> s1_sorted;
 };
 
 template <typename Sentence1>
@@ -659,10 +659,10 @@ struct CachedWRatio { (private)
 private:
     // todo somehow implement this using other ratios with creating PatternMatchVector
     // multiple times
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     CachedPartialRatio<CharT1> cached_partial_ratio;
-    detail::SplittedSentenceView<typename std::basic_string<CharT1>::iterator> tokens_s1;
-    std::basic_string<CharT1> s1_sorted;
+    detail::SplittedSentenceView<typename std::vector<CharT1>::iterator> tokens_s1;
+    std::vector<CharT1> s1_sorted;
     rapidfuzz::detail::BlockPatternMatchVector blockmap_s1_sorted;
 };
 
@@ -774,7 +774,7 @@ struct CachedQRatio { (private)
     double similarity(const Sentence2& s2, double score_cutoff = 0.0, double score_hint = 0.0) const;
 
 private:
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     CachedRatio<CharT1> cached_ratio;
 };
 
