--- cpp/test/Ice/threadPoolPriority/AllTests.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/Ice/threadPoolPriority/AllTests.cpp
@@ -26,7 +26,7 @@ allTests(Test::TestHelper* helper)
 #ifdef _WIN32
         test(1 == priority->getPriority());
 #else
-        test(50 == priority->getPriority());
+        test(31 == priority->getPriority());
 #endif
     }
     catch(...)
