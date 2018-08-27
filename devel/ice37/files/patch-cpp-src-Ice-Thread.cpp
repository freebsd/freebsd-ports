--- cpp/src/Ice/Thread.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/src/Ice/Thread.cpp
@@ -720,6 +720,12 @@ IceUtil::Thread::start(size_t stackSize,
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
