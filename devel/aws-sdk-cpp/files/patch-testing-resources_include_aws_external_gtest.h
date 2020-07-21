--- testing-resources/include/aws/external/gtest.h.orig	2020-07-20 22:34:31 UTC
+++ testing-resources/include/aws/external/gtest.h
@@ -11883,7 +11883,7 @@ class ValueArray2 {
 
  private:
   // No implementation - assignment is unsupported.
-  void operator=(const ValueArray2& other);
+  void operator=(const ValueArray2& other) = delete;
 
   const T1 v1_;
   const T2 v2_;
@@ -21259,4 +21259,4 @@ inline int RUN_ALL_TESTS() {
   return ::testing::UnitTest::GetInstance()->Run();
 }
 
-#endif  // GTEST_INCLUDE_GTEST_GTEST_H_
\ No newline at end of file
+#endif  // GTEST_INCLUDE_GTEST_GTEST_H_
