--- cpp/src/Ice/Thread.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/Ice/Thread.cpp
@@ -724,6 +724,12 @@ IceUtil::Thread::start(size_t stackSize, bool realtime
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
