--- ./src/mutex.h.orig	2007-06-11 11:16:23.000000000 -0400
+++ ./src/mutex.h	2014-08-11 09:59:15.000000000 -0400
@@ -58,7 +58,7 @@
 class mutex_locker
 {
  protected:
-	mutex& mymutex;
+	::mutex& mymutex;
  private:
 	mutex_locker();
 	mutex_locker(const mutex_locker& );
@@ -67,7 +67,7 @@
 	/// create mutex locker
 	///@param mtx - mutex to lock
 	///@note will instantly lock the mutex that was given as parameter
-	mutex_locker(mutex& mtx) : mymutex(mtx) { mymutex.lock(); }
+	mutex_locker(::mutex& mtx) : mymutex(mtx) { mymutex.lock(); }
 
 	/// destroy mutex locker
 	///@note will unlock the mutex that was given to the constructor
