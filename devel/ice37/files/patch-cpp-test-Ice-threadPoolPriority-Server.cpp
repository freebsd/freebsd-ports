--- cpp/test/Ice/threadPoolPriority/Server.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/Ice/threadPoolPriority/Server.cpp
@@ -43,7 +43,7 @@ run(int, char**, const Ice::Communicator
 #ifdef _WIN32
     communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "1");
 #else
-    communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "50");
+    communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "31");
 #endif
 
     Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("TestAdapter");
