--- Foundation/src/Thread_POSIX.cpp.orig	2022-10-31 17:44:32 UTC
+++ Foundation/src/Thread_POSIX.cpp
@@ -19,6 +19,13 @@
 #include "Poco/Timespan.h"
 #include "Poco/Timestamp.h"
 #include <signal.h>
+
+#if POCO_OS == POCO_OS_FREE_BSD
+#    include <sys/thr.h>
+#    include <pthread_np.h>
+#    include <osreldate.h>
+#endif
+
 #if defined(__sun) && defined(__SVR4)
 #	if !defined(__EXTENSIONS__)
 #		define __EXTENSIONS__
@@ -65,7 +72,10 @@ void setThreadName(pthread_t thread, const std::string
 namespace {
 void setThreadName(pthread_t thread, const std::string& threadName)
 {
-#if (POCO_OS == POCO_OS_MAC_OS_X)
+#if POCO_OS == POCO_OS_FREE_BSD && __FreeBSD_version <  1300000
+	pthread_set_name_np(pthread_self(), threadName.c_str());
+	return;
+#elif (POCO_OS == POCO_OS_MAC_OS_X)
 	pthread_setname_np(threadName.c_str()); // __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_2)
 #else
 	if (pthread_setname_np(thread, threadName.c_str()) == ERANGE && threadName.size() > 15)
@@ -273,11 +283,17 @@ long ThreadImpl::currentOsTidImpl()
 long ThreadImpl::currentOsTidImpl()
 {
 #if POCO_OS == POCO_OS_LINUX
-    return ::syscall(SYS_gettid);
+	return ::syscall(SYS_gettid);
 #elif POCO_OS == POCO_OS_MAC_OS_X
-    return ::pthread_mach_thread_np(::pthread_self());
+	return ::pthread_mach_thread_np(::pthread_self());
+#elif POCO_OS == POCO_OS_FREE_BSD
+	long id;
+	if(thr_self(&id) < 0) {
+		return 0;
+	}
+	return id;
 #else
-    return ::pthread_self();
+	return ::pthread_self();
 #endif
 }
 
