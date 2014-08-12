--- ./src/condvar.h.orig	2007-06-11 11:16:23.000000000 -0400
+++ ./src/condvar.h	2014-08-11 09:56:15.000000000 -0400
@@ -43,13 +43,13 @@
 
 	/// wait on condition
 	///@param m - mutex to encapsulate waiting condition
-	void wait(mutex& m);
+	void wait(::mutex& m);
 
 	/// wait on condition with timeout
 	///@param m - mutex to encapsulate waiting condition
 	///@param ms - timeout value in milliseconds
 	///@return true when woken up by signal, false on timeout
-	bool timed_wait(mutex& m, unsigned ms);
+	bool timed_wait(::mutex& m, unsigned ms);
 
 	/// send signal to threads that are waiting on the condition.
 	///@note Note that before sending the signal you must make the condition false that would
