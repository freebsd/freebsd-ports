--- extern/rapidfuzz-cpp/rapidfuzz/distance/DamerauLevenshtein.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/DamerauLevenshtein.hpp
@@ -140,7 +140,7 @@ struct CachedDamerauLevenshtein : public detail::Cache
         return damerau_levenshtein_distance(s1, s2, score_cutoff);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
 };
 
 template <typename Sentence1>
