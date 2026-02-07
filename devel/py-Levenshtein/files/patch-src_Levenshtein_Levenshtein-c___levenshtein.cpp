--- src/Levenshtein/Levenshtein-c/_levenshtein.cpp.orig	2023-09-26 11:15:28 UTC
+++ src/Levenshtein/Levenshtein-c/_levenshtein.cpp
@@ -119,10 +119,10 @@ class SymMap { (public)
     }
 };
 
-std::basic_string<uint32_t> lev_quick_median(const std::vector<RF_String>& strings,
-                                             const std::vector<double>& weights)
+std::vector<uint32_t> lev_quick_median(const std::vector<RF_String>& strings,
+                                       const std::vector<double>& weights)
 {
-    std::basic_string<uint32_t> median; /* the resulting string */
+    std::vector<uint32_t> median; /* the resulting string */
 
     /* first check whether the result would be an empty string
      * and compute resulting string length */
