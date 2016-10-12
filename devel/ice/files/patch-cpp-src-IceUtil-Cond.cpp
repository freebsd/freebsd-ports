--- cpp/src/IceUtil/Cond.cpp.orig	2016-10-12 00:34:17.622732906 +0200
+++ cpp/src/IceUtil/Cond.cpp	2016-10-12 00:34:40.133725906 +0200
@@ -332,7 +332,7 @@
         throw ThreadSyscallException(__FILE__, __LINE__, rc);
     }
 
-#if !defined(__hppa) && !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__hppa) && !defined(__APPLE__)
     rc = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC); 
     if(rc != 0)
     {
