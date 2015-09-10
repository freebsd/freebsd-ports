--- Common/FileUtil.cpp.orig	2015-02-26 20:05:06 UTC
+++ Common/FileUtil.cpp
@@ -35,6 +35,11 @@
 #include <stdlib.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/sysctl.h>		// KERN_PROC_PATHNAME
+#include <unistd.h>		// getpid
+#endif
+
 #if defined(__APPLE__)
 #include <CoreFoundation/CFString.h>
 #include <CoreFoundation/CFURL.h>
@@ -703,7 +708,7 @@ const std::string &GetExeDirectory()
 		ExePath = program_path;
 #endif
 
-#elif (defined(__APPLE__) && !defined(IOS)) || defined(__linux__)
+#elif (defined(__APPLE__) && !defined(IOS)) || defined(__linux__) || defined(KERN_PROC_PATHNAME)
 		char program_path[4096];
 		uint32_t program_path_size = sizeof(program_path) - 1;
 
@@ -711,6 +716,16 @@ const std::string &GetExeDirectory()
 		if (readlink("/proc/self/exe", program_path, 4095) > 0)
 #elif defined(__APPLE__) && !defined(IOS)
 		if (_NSGetExecutablePath(program_path, &program_path_size) == 0)
+#elif defined(KERN_PROC_PATHNAME)
+		int mib[4] = {
+			CTL_KERN,
+			KERN_PROC,
+			KERN_PROC_PATHNAME,
+			getpid()
+		};
+		size_t sz = program_path_size;
+
+		if (sysctl(mib, 4, program_path, &sz, NULL, 0) == 0)
 #else
 #error Unmatched ifdef.
 #endif
