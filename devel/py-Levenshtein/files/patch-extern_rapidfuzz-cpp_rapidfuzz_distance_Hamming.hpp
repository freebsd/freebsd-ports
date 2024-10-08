--- extern/rapidfuzz-cpp/rapidfuzz/distance/Hamming.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/Hamming.hpp
@@ -159,7 +159,7 @@ struct CachedHamming : public detail::CachedDistanceBa
         return detail::Hamming::distance(s1, s2, pad, score_cutoff, score_hint);
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     bool pad;
 };
 
