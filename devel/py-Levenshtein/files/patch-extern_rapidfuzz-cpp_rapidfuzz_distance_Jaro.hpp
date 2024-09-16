--- extern/rapidfuzz-cpp/rapidfuzz/distance/Jaro.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/Jaro.hpp
@@ -88,7 +88,7 @@ struct CachedJaro : public detail::CachedSimilarityBas
         return detail::jaro_similarity(PM, detail::Range(s1), s2, score_cutoff);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     detail::BlockPatternMatchVector PM;
 };
 
