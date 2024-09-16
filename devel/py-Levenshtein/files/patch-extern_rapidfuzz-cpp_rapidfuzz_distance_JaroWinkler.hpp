--- extern/rapidfuzz-cpp/rapidfuzz/distance/JaroWinkler.hpp.orig	2023-09-26 11:15:29 UTC
+++ extern/rapidfuzz-cpp/rapidfuzz/distance/JaroWinkler.hpp
@@ -103,7 +103,7 @@ struct CachedJaroWinkler : public detail::CachedSimila
     }
 
     double prefix_weight;
-    std::basic_string<CharT1> s1;
+    std::vector<CharT1> s1;
     detail::BlockPatternMatchVector PM;
 };
 
