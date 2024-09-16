--- extern/rapidfuzz-cpp/rapidfuzz/distance/Levenshtein.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/Levenshtein.hpp
@@ -476,7 +476,7 @@ struct CachedLevenshtein : public detail::CachedDistan
         return detail::generalized_levenshtein_distance(detail::Range(s1), s2, weights, score_cutoff);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     detail::BlockPatternMatchVector PM;
     LevenshteinWeightTable weights;
 };
