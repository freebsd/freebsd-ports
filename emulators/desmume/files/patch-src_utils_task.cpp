--- src/utils/task.cpp.orig	2015-10-30 09:34:37 UTC
+++ src/utils/task.cpp
@@ -23,9 +23,9 @@
 #include <windows.h>
 #else
 #include <pthread.h>
-#if defined HOST_LINUX
+#if defined HOST_LINUX || defined HOST_BSD
 #include <unistd.h>
-#elif defined HOST_BSD || defined HOST_DARWIN
+#elif defined HOST_DARWIN
 #include <sys/sysctl.h>
 #endif
 #endif // HOST_WINDOWS
@@ -37,9 +37,9 @@ int getOnlineCores (void)
 	SYSTEM_INFO sysinfo;
 	GetSystemInfo(&sysinfo);
 	return sysinfo.dwNumberOfProcessors;
-#elif defined HOST_LINUX
+#elif defined HOST_LINUX || defined HOST_BSD
 	return sysconf(_SC_NPROCESSORS_ONLN);
-#elif defined HOST_BSD || defined HOST_DARWIN
+#elif defined HOST_DARWIN
 	int cores;
 	int mib[4] = { CTL_HW, HW_NCPU, 0, 0 };
 	size_t len = sizeof(cores); //don't make this const, i guess sysctl can't take a const *
