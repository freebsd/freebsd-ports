--- lib/CThreadHelper.cpp.orig	2024-05-09 08:25:27 UTC
+++ lib/CThreadHelper.cpp
@@ -107,6 +107,8 @@ void setThreadName(const std::string &name)
 
 #elif defined(VCMI_APPLE)
 	pthread_setname_np(name.c_str());
+#elif defined(VCMI_FREEBSD)
+	pthread_setname_np(pthread_self(), name.c_str());
 #elif defined(VCMI_HAIKU)
 	rename_thread(find_thread(NULL), name.c_str());
 #elif defined(VCMI_UNIX)
