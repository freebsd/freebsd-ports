--- src/path-prefix.cpp.orig	2021-05-17 19:25:49 UTC
+++ src/path-prefix.cpp
@@ -20,6 +20,12 @@
 #include <mach-o/dyld.h> // for _NSGetExecutablePath
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include <cassert>
 #include <glib.h>
 #include <glibmm.h>
@@ -123,6 +129,15 @@ char const *get_program_name()
         if (!program_name) {
             g_warning("get_program_name() - g_file_read_link failed");
         }
+#elif defined(__FreeBSD__)
+       int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+       char buf[MAXPATHLEN];
+       size_t cb = sizeof(buf);
+       if (sysctl(mib, 4, buf, &cb, NULL, 0) == 0) {
+           program_name = realpath(buf, nullptr);
+       } else {
+           g_warning("get_program_name() - sysctl failed");
+       }
 #else
 #warning get_program_name() - no known way to obtain executable name on this platform
         g_info("get_program_name() - no known way to obtain executable name on this platform");
