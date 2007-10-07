--- IlmThread/IlmThreadPool.cpp.orig	2006-12-09 06:59:36.000000000 +0900
+++ IlmThread/IlmThreadPool.cpp	2007-10-07 23:29:07.000000000 +0900
@@ -247,7 +247,7 @@
     // an error like: "pure virtual method called"
     //
 
-    for (int i = 0; i < numThreads; i++)
+    for (unsigned int i = 0; i < numThreads; i++)
     {
 	taskSemaphore.post();
 	threadSemaphore.wait();
@@ -364,19 +364,19 @@
 
     Lock lock (_data->threadMutex);
 
-    if (count > _data->numThreads)
+    if ((unsigned int)count > _data->numThreads)
     {
 	//
         // Add more threads
 	//
 
-        while (_data->numThreads < count)
+        while (_data->numThreads < (unsigned int)count)
         {
             _data->threads.push_back (new WorkerThread (_data));
             _data->numThreads++;
         }
     }
-    else if (count < _data->numThreads)
+    else if ((unsigned int)count < _data->numThreads)
     {
 	//
 	// Wait until all existing threads are finished processing,
@@ -389,7 +389,7 @@
         // Add in new threads
 	//
 
-        while (_data->numThreads < count)
+        while (_data->numThreads < (unsigned int)count)
         {
             _data->threads.push_back (new WorkerThread (_data));
             _data->numThreads++;
