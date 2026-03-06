--- src/libslic3r/utils.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/libslic3r/utils.cpp
@@ -41,6 +41,11 @@
 		#include <dirent.h>
 		#include <stdio.h>
 	#endif
+	#ifdef __FreeBSD__
+		#include <sys/stat.h>
+		#include <dirent.h>
+		#include <stdio.h>
+	#endif
 #endif
 
 #include <boost/log/core.hpp>
@@ -847,7 +852,7 @@ CopyFileResult copy_file_inner(const std::string& from
 	// That may happen when copying on some exotic file system, for example Linux on Chrome.
 	copy_file_linux(source, target, ec);
 #else // __linux__
-	boost::filesystem::copy_file(source, target, boost::filesystem::copy_option::overwrite_if_exists, ec);
+	boost::filesystem::copy_file(source, target, boost::filesystem::copy_options::overwrite_existing, ec);
 #endif // __linux__
 	if (ec) {
 		error_message = ec.message();
@@ -1205,6 +1210,12 @@ std::string get_process_name(int pid)
 	char* p = pathbuf;
 	while (auto q = strchr(p + 1, '/')) p = q;
 	return p;
+#elif defined(__FreeBSD__)
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+    char pathbuf[PATH_MAX];
+    size_t cb = sizeof(pathbuf);
+    if (sysctl(mib, 4, pathbuf, &cb, NULL, 0) != 0) return std::string();
+    return boost::filesystem::path(pathbuf).filename().string();
 #else
     char pathbuf[512]  = {0};
     char proc_path[32] = "/proc/self/exe";
@@ -1484,7 +1495,7 @@ bool makedir(const std::string path) {
 #ifdef WIN32
 	if (_access(path.c_str(), 0) != 0)
 		return _mkdir(path.c_str()) == 0;
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 	if (opendir(path.c_str()) == NULL) {
 		return mkdir(path.c_str(), 0777) == 0;
 	}
