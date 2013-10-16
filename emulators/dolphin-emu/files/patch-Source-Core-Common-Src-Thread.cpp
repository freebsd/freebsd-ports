--- Source/Core/Common/Src/Thread.cpp.orig	2013-09-17 16:24:41.000000000 +0200
+++ Source/Core/Common/Src/Thread.cpp	2013-09-17 16:41:54.000000000 +0200
@@ -7,7 +7,7 @@
 
 #ifdef __APPLE__
 #include <mach/mach.h>
-#elif defined BSD4_4
+#elif defined BSD4_4 || defined __FreeBSD__
 #include <pthread_np.h>
 #endif
 
@@ -92,8 +92,12 @@
 #ifdef __APPLE__
 	thread_policy_set(pthread_mach_thread_np(thread),
 		THREAD_AFFINITY_POLICY, (integer_t *)&mask, 1);
-#elif (defined __linux__ || defined BSD4_4) && !(defined ANDROID)
+#elif (defined __linux__ || defined BSD4_4 || defined __FreeBSD__) && !(defined ANDROID)
+#if defined __FreeBSD__
+	cpuset_t cpu_set;
+#else
 	cpu_set_t cpu_set;
+#endif
 	CPU_ZERO(&cpu_set);
 
 	for (int i = 0; i != sizeof(mask) * 8; ++i)
@@ -121,8 +125,10 @@
 
 void SetCurrentThreadName(const char* szThreadName)
 {
-#ifdef __APPLE__
+#if defined __APPLE__
 	pthread_setname_np(szThreadName);
+#elif defined __FreeBSD__
+	pthread_set_name_np(pthread_self(), szThreadName);
 #else
 	pthread_setname_np(pthread_self(), szThreadName);
 #endif
