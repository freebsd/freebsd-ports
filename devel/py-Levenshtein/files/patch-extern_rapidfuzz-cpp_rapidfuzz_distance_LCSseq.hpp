--- extern/rapidfuzz-cpp/rapidfuzz/distance/LCSseq.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/LCSseq.hpp
@@ -224,7 +224,7 @@ struct CachedLCSseq (private)
         return detail::lcs_seq_similarity(PM, detail::Range(s1), s2, score_cutoff);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     detail::BlockPatternMatchVector PM;
 };
 
