--- server/plugins/DiskIO_UGens.cpp.orig	2017-03-20 15:18:39 UTC
+++ server/plugins/DiskIO_UGens.cpp
@@ -168,7 +168,7 @@ struct DiskIOThread
 #endif
 
 	std::atomic<bool> mRunning;
-	thread mThread;
+	std::thread mThread;
 
 	DiskIOThread():
 		mRunning(false)
@@ -188,7 +188,7 @@ struct DiskIOThread
 		using namespace std;
 		mRunning.store(true);
 
-		mThread = move( thread( bind(&DiskIOThread::ioThreadFunc, this) ) );
+		mThread = move( std::thread( bind(&DiskIOThread::ioThreadFunc, this) ) );
 	}
 
 	bool Write(DiskIOMsg& data)
