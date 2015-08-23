--- src/libcore/thread.cpp.orig	2015-07-15 10:37:38 UTC
+++ src/libcore/thread.cpp
@@ -28,7 +28,10 @@
 
 // Required for native thread functions
 #if defined(__LINUX__)
-# include <sys/prctl.h>
+# include <pthread.h>
+# if defined(__FreeBSD__)
+#  include <pthread_np.h>
+# endif
 #elif defined(__OSX__)
 # include <pthread.h>
 #elif defined(__WINDOWS__)
@@ -320,7 +323,7 @@ void Thread::setCoreAffinity(int coreID)
 	if (!d->running)
 		return;
 
-#if defined(__OSX__)
+#if defined(__OSX__) || defined(__FreeBSD__)
 	/* CPU affinity not supported on OSX */
 #elif defined(__LINUX__)
 	int nCores = sysconf(_SC_NPROCESSORS_CONF),
@@ -440,10 +443,7 @@ void Thread::dispatch(Thread *thread) {
 	if (!thread->getName().empty()) {
 		const std::string threadName = "Mitsuba: " + thread->getName();
 #if defined(__LINUX__)
-		// Disabled for now, since it is not yet widely available in glibc
-		// pthread_setname_np(pthread_self(), threadName.c_str());
-
-		prctl(PR_SET_NAME, threadName.c_str());
+		pthread_set_name_np(pthread_self(), threadName.c_str());
 #elif defined(__OSX__)
 		pthread_setname_np(threadName.c_str());
 #elif defined(__WINDOWS__)
@@ -638,7 +638,7 @@ void Thread::initializeOpenMP(size_t thr
 			const std::string threadName = "Mitsuba: " + thread->getName();
 
 			#if defined(__LINUX__)
-				prctl(PR_SET_NAME, threadName.c_str());
+				pthread_set_name_np(pthread_self(), threadName.c_str());
 			#elif defined(__OSX__)
 				pthread_setname_np(threadName.c_str());
 			#elif defined(__WINDOWS__)
