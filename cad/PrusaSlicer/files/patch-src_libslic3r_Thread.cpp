Note that this patch may be removed after FreeBSD 11.x EoL
as latest FreeBSD versions have proper
pthread_setname_np/pthread_getname_np support.

--- src/libslic3r/Thread.cpp.orig	2021-01-11 13:01:51 UTC
+++ src/libslic3r/Thread.cpp
@@ -4,6 +4,7 @@
 #else
 	// any posix system
 	#include <pthread.h>
+	#include <pthread_np.h>
 #endif
 
 #include <atomic>
@@ -161,26 +162,27 @@ std::optional<std::string> get_current_thread_name()
 // posix
 bool set_thread_name(std::thread &thread, const char *thread_name)
 {
-   	pthread_setname_np(thread.native_handle(), thread_name);
+   	pthread_set_name_np(thread.native_handle(), thread_name);
 	return true;
 }
 
 bool set_thread_name(boost::thread &thread, const char *thread_name)
 {
-   	pthread_setname_np(thread.native_handle(), thread_name);
+   	pthread_set_name_np(thread.native_handle(), thread_name);
 	return true;
 }
 
 bool set_current_thread_name(const char *thread_name)
 {
-	pthread_setname_np(pthread_self(), thread_name);
+	pthread_set_name_np(pthread_self(), thread_name);
 	return true;
 }
 
 std::optional<std::string> get_current_thread_name()
 {
 	char buf[16];
-	return std::string(pthread_getname_np(pthread_self(), buf, 16) == 0 ? buf : "");
+	pthread_get_name_np(pthread_self(), buf, 16);
+	return std::string(buf);
 }
 
 #endif
