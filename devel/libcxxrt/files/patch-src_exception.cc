--- src/exception.cc.orig	2013-12-26 03:11:27 UTC
+++ src/exception.cc
@@ -304,13 +304,17 @@ static pthread_key_t eh_key;
 static void exception_cleanup(_Unwind_Reason_Code reason, 
                               struct _Unwind_Exception *ex)
 {
-	__cxa_free_exception(static_cast<void*>(ex));
+	// Exception layout:
+	// [__cxa_exception [_Unwind_Exception]] [exception object]
+	//
+	// __cxa_free_exception expects a pointer to the exception object
+	__cxa_free_exception(static_cast<void*>(ex + 1));
 }
 static void dependent_exception_cleanup(_Unwind_Reason_Code reason, 
                               struct _Unwind_Exception *ex)
 {
 
-	__cxa_free_dependent_exception(static_cast<void*>(ex));
+	__cxa_free_dependent_exception(static_cast<void*>(ex + 1));
 }
 
 /**
@@ -340,7 +344,8 @@ static void thread_cleanup(void* thread_
 		if (info->foreign_exception_state != __cxa_thread_info::none)
 		{
 			_Unwind_Exception *e = reinterpret_cast<_Unwind_Exception*>(info->globals.caughtExceptions);
-			e->exception_cleanup(_URC_FOREIGN_EXCEPTION_CAUGHT, e);
+			if (e->exception_cleanup)
+				e->exception_cleanup(_URC_FOREIGN_EXCEPTION_CAUGHT, e);
 		}
 		else
 		{
@@ -1270,12 +1275,13 @@ extern "C" void __cxa_end_catch()
 	
 	if (ti->foreign_exception_state != __cxa_thread_info::none)
 	{
-		globals->caughtExceptions = 0;
 		if (ti->foreign_exception_state != __cxa_thread_info::rethrown)
 		{
 			_Unwind_Exception *e = reinterpret_cast<_Unwind_Exception*>(ti->globals.caughtExceptions);
-			e->exception_cleanup(_URC_FOREIGN_EXCEPTION_CAUGHT, e);
+			if (e->exception_cleanup)
+				e->exception_cleanup(_URC_FOREIGN_EXCEPTION_CAUGHT, e);
 		}
+		globals->caughtExceptions = 0;
 		ti->foreign_exception_state = __cxa_thread_info::none;
 		return;
 	}
