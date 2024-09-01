--- test/distance/tests-Hamming.cpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/tests-Hamming.cpp
@@ -110,13 +110,13 @@ TEST_CASE("Hamming_editops")
 
     {
         rapidfuzz::Editops ops = rapidfuzz::hamming_editops(s, d);
-        REQUIRE(d == rapidfuzz::editops_apply<char>(ops, s, d));
+        REQUIRE(std::vector<char>{d.begin(), d.end()} == rapidfuzz::editops_apply<char>(ops, s, d));
         REQUIRE(ops.get_src_len() == s.size());
         REQUIRE(ops.get_dest_len() == d.size());
     }
     {
         rapidfuzz::Editops ops = rapidfuzz::hamming_editops(d, s);
-        REQUIRE(s == rapidfuzz::editops_apply<char>(ops, d, s));
+        REQUIRE(std::vector<char>{s.begin(), s.end()} == rapidfuzz::editops_apply<char>(ops, d, s));
         REQUIRE(ops.get_src_len() == d.size());
         REQUIRE(ops.get_dest_len() == s.size());
     }
