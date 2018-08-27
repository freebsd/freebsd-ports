--- cpp/test/Ice/threadPoolPriority/ServerCustomThreadPool.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/Ice/threadPoolPriority/ServerCustomThreadPool.cpp
@@ -48,7 +48,7 @@ run(int, char**, const Ice::Communicator
     communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "1");
 #else
     communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "10");
-    communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "50");
+    communicator->getProperties()->setProperty("TestAdapter.ThreadPool.ThreadPriority", "31");
 #endif
     Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("TestAdapter");
     Ice::ObjectPtr object = ICE_MAKE_SHARED(PriorityI, adapter);
