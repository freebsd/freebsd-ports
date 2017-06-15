--- sal/qa/osl/mutex/osl_Mutex.cxx.orig	2016-06-21 21:57:07 UTC
+++ sal/qa/osl/mutex/osl_Mutex.cxx
@@ -729,7 +729,7 @@ namespace osl_ClearableGuard
 
 		myThread.join();
 		
-		ASSERT_TRUE(nSec < 7 && nSec > 1) << "ClearableGuard method: clear";
+		ASSERT_TRUE(nSec <= 7 && nSec > 1) << "ClearableGuard method: clear";
 	}
 	
 	TEST_F(clear, clear_002 )
