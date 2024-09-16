--- extern/rapidfuzz-cpp/rapidfuzz/distance/Postfix.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/Postfix.hpp
@@ -91,7 +91,7 @@ struct CachedPostfix : public detail::CachedSimilarity
         return detail::Postfix::similarity(s1, s2, score_cutoff, score_hint);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
 };
 
 template <typename Sentence1>
