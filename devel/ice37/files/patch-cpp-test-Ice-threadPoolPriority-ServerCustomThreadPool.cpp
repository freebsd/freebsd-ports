--- cpp/test/Ice/threadPoolPriority/ServerCustomThreadPool.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/Ice/threadPoolPriority/ServerCustomThreadPool.cpp
@@ -51,7 +51,7 @@ ServerCustomThreadPool::run(int argc, char** argv)
     communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "1");
 #else
     communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "10");
-    communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "50");
+    communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "31");
 #endif
     Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("TestAdapter");
     Ice::ObjectPtr object = ICE_MAKE_SHARED(PriorityI, adapter);
