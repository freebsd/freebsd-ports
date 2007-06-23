--- src/Thread.cpp.orig	Sat Mar 17 10:20:15 2007
+++ src/Thread.cpp	Sat Jun 23 09:54:56 2007
@@ -78,7 +78,7 @@
 #ifdef WIN32
 	return GetCurrentThreadId();
 #else
-	return pthread_self();
+	return (unsigned long)pthread_self();
 #endif
 }
 
@@ -277,10 +277,10 @@
 	if(SetThreadAffinityMask(m_hThread,mask)==0)
 		throw ThreadException("Failed to set affinity");
 #else
+#ifdef HAVE_PTHREAD_SETAFFINITY_NP 
 	cpu_set_t cpuset;
 	CPU_ZERO(&cpuset);
 	CPU_SET(cpu, &cpuset);
-#ifdef HAVE_PTHREAD_SETAFFINITY_NP 
 #ifndef P2_PTHREAD_SETAFFINITY
 	if(pthread_setaffinity_np(m_hThread, sizeof(cpuset), &cpuset)!=0)
 		throw ThreadException("Failed to set affinity");
