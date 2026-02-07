--- sal/qa/osl/mutex/osl_Mutex.cxx.orig	2016-09-10 13:55:07 UTC
+++ sal/qa/osl/mutex/osl_Mutex.cxx
@@ -773,7 +773,7 @@ namespace osl_ClearableGuard
 			myThread.join();
 			
 			CPPUNIT_ASSERT_MESSAGE("ClearableGuard method: clear", 
-				nSec < 7 && nSec > 1);
+				nSec <= 7 && nSec > 1);
 		}
 		
 		void clear_002( )
