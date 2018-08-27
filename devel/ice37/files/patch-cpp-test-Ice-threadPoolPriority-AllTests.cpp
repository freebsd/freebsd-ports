--- cpp/test/Ice/threadPoolPriority/AllTests.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/Ice/threadPoolPriority/AllTests.cpp
@@ -30,7 +30,7 @@ allTests(const Ice::CommunicatorPtr& com
 #ifdef _WIN32
         test(1 == priority->getPriority());
 #else
-        test(50 == priority->getPriority());
+        test(31 == priority->getPriority());
 #endif
     }
     catch(...)
