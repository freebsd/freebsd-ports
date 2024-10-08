--- extern/rapidfuzz-cpp/rapidfuzz/distance/OSA.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/OSA.hpp
@@ -267,7 +267,7 @@ struct CachedOSA (private)
         return (res <= score_cutoff) ? res : score_cutoff + 1;
     }
 
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     detail::BlockPatternMatchVector PM;
 };
 
