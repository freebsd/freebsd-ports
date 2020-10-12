--- src/util/u_process.c.orig	2020-10-05 09:53:46 UTC
+++ src/util/u_process.c
@@ -44,6 +44,11 @@
 #include <mach-o/dyld.h>
 #endif
 
+#if DETECT_OS_FREEBSD
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(__linux__) && defined(HAVE_PROGRAM_INVOCATION_NAME)
 
 static char *path = NULL;
@@ -175,6 +180,14 @@ util_get_process_exec_path(char* process_path, size_t 
    int result = _NSGetExecutablePath(process_path, &bufSize);
 
    return (result == 0) ? strlen(process_path) : 0;
+#elif DETECT_OS_FREEBSD
+   int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+   size_t read_len = len;
+
+   (void) sysctl(mib, 4, process_path, &read_len, NULL, 0);
+   process_path[len - 1] = '\0';
+
+   return read_len;
 #elif DETECT_OS_UNIX
    ssize_t r;
 
