--- projects/SelfTest/UsageTests/ToStringVariant.tests.cpp.orig	2022-10-16 09:02:17 UTC
+++ projects/SelfTest/UsageTests/ToStringVariant.tests.cpp
@@ -10,12 +10,12 @@ struct MyType1 {
 struct MyType1 {
     MyType1() = default;
     [[noreturn]] MyType1(MyType1 const&) { throw 1; }
-    MyType1& operator=(MyType1 const&) { throw 3; }
+    [[noreturn]] MyType1& operator=(MyType1 const&) { throw 3; }
 };
 struct MyType2 {
     MyType2() = default;
     [[noreturn]] MyType2(MyType2 const&) { throw 2; }
-    MyType2& operator=(MyType2 const&) { throw 4; }
+    [[noreturn]] MyType2& operator=(MyType2 const&) { throw 4; }
 };
 
 TEST_CASE( "variant<std::monostate>", "[toString][variant][approvals]")
