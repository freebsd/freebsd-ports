--- src/utils.c.orig	2014-04-07 11:37:35.909060780 -0400
+++ src/utils.c	2014-04-07 11:53:24.429168115 -0400
@@ -19,6 +19,11 @@
 #include "utils.h"
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+  #include <sys/types.h>
+  #include <sys/sysctl.h>
+#endif
+
 #ifdef __APPLE__
   #include "TargetConditionals.h"
   #ifdef TARGET_OS_MAC
@@ -95,14 +100,19 @@ const char* executable_path(void) {
   static int calculated = 0;
 
   if (!calculated) {
-#ifdef __linux
+#if defined(__linux)
     ssize_t res = readlink("/proc/self/exe", path_buffer, sizeof(path_buffer));
     assert(res != -1);
-#elif __APPLE__
+#elif defined(__FreeBSD__)
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+    size_t size = sizeof(path_buffer);
+    int res = sysctl(mib, 4, path_buffer, &size, NULL, 0);
+    assert(res == 0);
+#elif defined(__APPLE__)
     uint32_t size = sizeof(path_buffer);
     int res = _NSGetExecutablePath(path_buffer, &size);
     assert(res == 0);
-#elif _WIN32 || _WIN64
+#elif defined(_WIN32) || defined(_WIN64)
     // NOTE: for "C:\\opencc.exe" on Windows, the returned path "C:" is
     // incorrect until a '/' is appended to it later in try_open_file()
     DWORD res = GetModuleFileNameA(NULL, path_buffer, PATH_BUFFER_SIZE);
@@ -110,7 +120,7 @@ const char* executable_path(void) {
 #else
     /* Other unsupported os */
     assert(0);
-#endif /* ifdef __linux */
+#endif /* if defined(__linux) */
     char* last_sep = strrchr(path_buffer, PATH_SEPARATOR);
     assert(last_sep != NULL);
     *last_sep = '\0';
