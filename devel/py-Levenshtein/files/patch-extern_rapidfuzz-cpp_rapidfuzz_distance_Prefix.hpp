--- extern/rapidfuzz-cpp/rapidfuzz/distance/Prefix.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/Prefix.hpp
@@ -91,7 +91,7 @@ struct CachedPrefix : public detail::CachedSimilarityB
         return detail::Prefix::similarity(s1, s2, score_cutoff, score_cutoff);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
 };
 
 template <typename Sentence1>
