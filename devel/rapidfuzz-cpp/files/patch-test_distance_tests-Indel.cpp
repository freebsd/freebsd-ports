--- test/distance/tests-Indel.cpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/tests-Indel.cpp
@@ -277,7 +277,7 @@ TEST_CASE("Indel")
             REQUIRE(indel_distance(s1, s2) == 231);
 
             rapidfuzz::Editops ops = rapidfuzz::indel_editops(s1, s2);
-            REQUIRE(s2 == rapidfuzz::editops_apply<char>(ops, s1, s2));
+            REQUIRE(std::vector<char>{s2.begin(), s2.end()} == rapidfuzz::editops_apply<char>(ops, s1, s2));
         }
     }
 }
