--- cpp/test/Ice/threadPoolPriority/Server.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/Ice/threadPoolPriority/Server.cpp
@@ -46,7 +46,7 @@ Server::run(int argc, char** argv)
 #ifdef _WIN32
     communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "1");
 #else
-    communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "50");
+    communicator->getProperties()->setProperty("Ice.ThreadPool.Server.ThreadPriority", "31");
 #endif
 
     Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("TestAdapter");
