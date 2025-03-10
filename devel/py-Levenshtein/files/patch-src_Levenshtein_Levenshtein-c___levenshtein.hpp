--- src/Levenshtein/Levenshtein-c/_levenshtein.hpp.orig	2023-09-26 11:15:28 UTC
+++ src/Levenshtein/Levenshtein-c/_levenshtein.hpp
@@ -141,10 +141,10 @@ static inline std::vector<uint32_t> make_symlist(const
  * Returns: The generalized median, as a newly allocated string; its length
  *          is stored in @medlength.
  **/
-static inline std::basic_string<uint32_t> lev_greedy_median(const std::vector<RF_String>& strings,
-                                                            const std::vector<double>& weights)
+static inline std::vector<uint32_t> lev_greedy_median(const std::vector<RF_String>& strings,
+                                                      const std::vector<double>& weights)
 {
-    std::basic_string<uint32_t> result_median;
+    std::vector<uint32_t> result_median;
 
     /* find all symbols */
     std::vector<uint32_t> symlist = make_symlist(strings);
@@ -335,13 +335,13 @@ static inline double finish_distance_computations(cons
  *
  * Returns: The improved generalized median
  **/
-static inline std::basic_string<uint32_t> lev_median_improve(const RF_String& string,
-                                                             const std::vector<RF_String>& strings,
-                                                             const std::vector<double>& weights)
+static inline std::vector<uint32_t> lev_median_improve(const RF_String& string,
+                                                       const std::vector<RF_String>& strings,
+                                                       const std::vector<double>& weights)
 {
     /* find all symbols */
     std::vector<uint32_t> symlist = make_symlist(strings);
-    if (symlist.empty()) return std::basic_string<uint32_t>();
+    if (symlist.empty()) return std::vector<uint32_t>();
 
     /* allocate and initialize per-string matrix rows and a common work buffer */
     std::vector<std::unique_ptr<size_t[]>> rows(strings.size());
@@ -459,11 +459,11 @@ static inline std::basic_string<uint32_t> lev_median_i
         }
     }
 
-    return std::basic_string<uint32_t>(median, medlen);
+    return std::vector<uint32_t>(median, median + medlen);
 }
 
-std::basic_string<uint32_t> lev_quick_median(const std::vector<RF_String>& strings,
-                                             const std::vector<double>& weights);
+std::vector<uint32_t> lev_quick_median(const std::vector<RF_String>& strings,
+                                       const std::vector<double>& weights);
 
 /**
  * lev_set_median:
@@ -477,8 +477,8 @@ std::basic_string<uint32_t> lev_quick_median(const std
  *
  * Returns: The set median
  **/
-static inline std::basic_string<uint32_t> lev_set_median(const std::vector<RF_String>& strings,
-                                                         const std::vector<double>& weights)
+static inline std::vector<uint32_t> lev_set_median(const std::vector<RF_String>& strings,
+                                                   const std::vector<double>& weights)
 {
     size_t minidx = 0;
     double mindist = std::numeric_limits<double>::max();
@@ -521,7 +521,7 @@ static inline std::basic_string<uint32_t> lev_set_medi
     }
 
     return visit(strings[minidx], [&](auto s1) {
-        return std::basic_string<uint32_t>(std::begin(s1), std::end(s1));
+        return std::vector<uint32_t>(std::begin(s1), std::end(s1));
     });
 }
 
