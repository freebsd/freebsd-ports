--- cpp/src/Ice/Thread.cpp.orig	2023-11-06 09:24:19 UTC
+++ cpp/src/Ice/Thread.cpp
@@ -482,6 +482,12 @@ IceUtil::Thread::start(size_t stackSize, bool realtime
             stackSize = stackSize / 4096 * 4096 + 4096;
         }
 #endif
+#if defined(__FreeBSD__)
+        if(stackSize < 16384)
+        {
+            stackSize = 16384;
+        }
+#endif
         rc = pthread_attr_setstacksize(&attr, stackSize);
         if(rc != 0)
         {
