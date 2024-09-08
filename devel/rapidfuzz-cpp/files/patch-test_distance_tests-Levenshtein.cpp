--- test/distance/tests-Levenshtein.cpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/tests-Levenshtein.cpp
@@ -63,9 +63,9 @@ template <typename T>
 }
 
 template <typename T>
-std::basic_string<T> get_subsequence(const std::basic_string<T>& s, ptrdiff_t pos, ptrdiff_t len)
+std::vector<T> get_subsequence(const std::vector<T>& s, ptrdiff_t pos, ptrdiff_t len)
 {
-    return std::basic_string<T>(std::begin(s) + pos, std::begin(s) + pos + len);
+    return std::vector<T>(std::begin(s) + pos, std::begin(s) + pos + len);
 }
 
 template <typename Sentence1, typename Sentence2>
@@ -233,7 +233,7 @@ TEST_CASE("Levenshtein_editops")
     std::string d = "XYZLorem ABC iPsum";
 
     rapidfuzz::Editops ops = rapidfuzz::levenshtein_editops(s, d);
-    REQUIRE(d == rapidfuzz::editops_apply<char>(ops, s, d));
+    REQUIRE(std::vector<char>{d.begin(), d.end()} == rapidfuzz::editops_apply<char>(ops, s, d));
     REQUIRE(ops.get_src_len() == s.size());
     REQUIRE(ops.get_dest_len() == d.size());
 }
@@ -293,21 +293,21 @@ TEST_CASE("Levenshtein_editops[fuzzing_regressions]")
         std::string s1 = "b";
         std::string s2 = "aaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
         rapidfuzz::Editops ops = rapidfuzz::levenshtein_editops(s1, s2);
-        REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops, s1, s2));
+        REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops, s1, s2));
     }
 
     {
         std::string s1 = "aa";
         std::string s2 = "abb";
         rapidfuzz::Editops ops = rapidfuzz::levenshtein_editops(s1, s2);
-        REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops, s1, s2));
+        REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops, s1, s2));
     }
 
     {
         std::string s1 = str_multiply(std::string("abb"), 8 * 64);
         std::string s2 = str_multiply(std::string("ccccca"), 8 * 64);
         rapidfuzz::Editops ops = rapidfuzz::levenshtein_editops(s1, s2);
-        REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops, s1, s2));
+        REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops, s1, s2));
     }
 }
 
@@ -352,7 +352,7 @@ TEST_CASE("Levenshtein small band")
         rapidfuzz::Editops ops1;
         rapidfuzz::detail::levenshtein_align(ops1, rapidfuzz::detail::Range(s1),
                                              rapidfuzz::detail::Range(s2));
-        REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops1, s1, s2));
+        REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops1, s1, s2));
         rapidfuzz::Editops ops2;
         rapidfuzz::detail::levenshtein_align(ops2, rapidfuzz::detail::Range(s1), rapidfuzz::detail::Range(s2),
                                              ops1.size());
@@ -400,7 +400,7 @@ TEST_CASE("Levenshtein small band")
         rapidfuzz::Editops ops1;
         rapidfuzz::detail::levenshtein_align(ops1, rapidfuzz::detail::Range(s1),
                                              rapidfuzz::detail::Range(s2));
-        REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops1, s1, s2));
+        REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops1, s1, s2));
         rapidfuzz::Editops ops2;
         rapidfuzz::detail::levenshtein_align(ops2, rapidfuzz::detail::Range(s1), rapidfuzz::detail::Range(s2),
                                              ops1.size());
@@ -416,8 +416,8 @@ TEST_CASE("Levenshtein large band (python-Levenshtein 
     REQUIRE(example2.size() == 5569);
 
     {
-        std::basic_string<uint8_t> s1 = get_subsequence(example1, 3718, 1509);
-        std::basic_string<uint8_t> s2 = get_subsequence(example2, 2784, 2785);
+        std::vector<uint8_t> s1 = get_subsequence(example1, 3718, 1509);
+        std::vector<uint8_t> s2 = get_subsequence(example2, 2784, 2785);
 
         REQUIRE(rapidfuzz::levenshtein_distance(s1, s2) == 1587);
 
@@ -440,8 +440,8 @@ TEST_CASE("Levenshtein large band (ocr example)")
     REQUIRE(ocr_example2.size() == 107244);
 
     {
-        std::basic_string<uint8_t> s1 = get_subsequence(ocr_example1, 51, 6541);
-        std::basic_string<uint8_t> s2 = get_subsequence(ocr_example2, 51, 6516);
+        std::vector<uint8_t> s1 = get_subsequence(ocr_example1, 51, 6541);
+        std::vector<uint8_t> s2 = get_subsequence(ocr_example2, 51, 6516);
 
         rapidfuzz::Editops ops1;
         rapidfuzz::detail::levenshtein_align(ops1, rapidfuzz::detail::Range(s1),
