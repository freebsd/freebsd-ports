--- projects/SelfTest/IntrospectiveTests/String.tests.cpp.orig	2022-10-16 09:02:17 UTC
+++ projects/SelfTest/IntrospectiveTests/String.tests.cpp
@@ -141,7 +141,7 @@ TEST_CASE("StringRef at compilation time", "[Strings][
         STATIC_REQUIRE(sr1.size() == 3);
         STATIC_REQUIRE(sr1.isNullTerminated());
 
-        using Catch::operator"" _sr;
+        using Catch::operator""_sr;
         constexpr auto sr2 = ""_sr;
         STATIC_REQUIRE(sr2.empty());
         STATIC_REQUIRE(sr2.size() == 0);
