--- cpp/src/Ice/ThreadPool.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/Ice/ThreadPool.cpp
@@ -17,6 +17,10 @@
 #   include <Ice/StringConverter.h>
 #endif
 
+#if defined(__FreeBSD__)
+#   include <sys/sysctl.h>
+#endif
+
 using namespace std;
 using namespace Ice;
 using namespace Ice::Instrumentation;
@@ -303,8 +307,8 @@ IceInternal::ThreadPool::ThreadPool(const InstancePtr&
     int nProcessors = sysInfo.dwNumberOfProcessors;
 #   elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
     static int ncpu[2] = { CTL_HW, HW_NCPU };
-    size_t sz = sizeof(nProcessors);
     int nProcessors;
+    size_t sz = sizeof(nProcessors);
     if(sysctl(ncpu, 2, &nProcessors, &sz, 0, 0) == -1)
     {
         nProcessors = 1;
