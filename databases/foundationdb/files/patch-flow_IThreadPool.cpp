--- flow/IThreadPool.cpp.orig	2018-04-28 14:40:31 UTC
+++ flow/IThreadPool.cpp
@@ -35,7 +35,7 @@ class ThreadPool : public IThreadPool, p
 		Event stopped;
 		static thread_local IThreadPoolReceiver* threadUserObject;
 		explicit Thread(ThreadPool *pool, IThreadPoolReceiver *userObject) : pool(pool), userObject(userObject) {}
-		~Thread() { ASSERT(!userObject); }
+		~Thread() { ASSERT_ABORT(!userObject); }
 
 		void run() {
 			deprioritizeThread();
