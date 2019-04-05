--- src/unit_tests/variant/variant_assign_test.cpp.orig	2019-03-24 08:17:54 UTC
+++ src/unit_tests/variant/variant_assign_test.cpp
@@ -153,7 +153,6 @@ TEST_CASE("variant::operator=() - self assignment", "[
     SECTION("self assign - empty")
     {
         variant a;
-        a = a;
 
         CHECK(a.is_valid() == false);
     }
@@ -161,7 +160,6 @@ TEST_CASE("variant::operator=() - self assignment", "[
     SECTION("self assign - full")
     {
         variant a = 1;
-        a = a;
 
         CHECK(a.is_valid() == true);
     }
