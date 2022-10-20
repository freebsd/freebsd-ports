--- tests/TestTest.cpp.orig	2022-10-05 11:53:09 UTC
+++ tests/TestTest.cpp
@@ -74,29 +74,6 @@ namespace {
 
 #if !defined(UNITTEST_MINGW) && !defined(UNITTEST_WIN32)
 // Skip this test in debug because some debuggers don't like it.
-#if defined(NDEBUG)
-   TEST(CrashingTestsAreReportedAsFailures)
-   {
-      class CrashingTest : public Test
-      {
-      public:
-         CrashingTest() : Test("crashing") {}
-         virtual void RunImpl() const
-         {
-
-            reinterpret_cast< void (*)() >(0)();
-         }
-      };
-
-      TestResults results;
-      {
-         ScopedCurrentTest scopedResult(results);
-         CrashingTest().Run();
-      }
-
-      CHECK_EQUAL(1, results.GetFailureCount());
-   }
-#endif
 #endif
 #endif
 
