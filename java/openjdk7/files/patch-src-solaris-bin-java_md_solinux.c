--- jdk/src/solaris/bin/java_md_solinux.c.orig
+++ jdk/src/solaris/bin/java_md_solinux.c
@@ -35,6 +35,9 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 #include "manifest_info.h"
 #include "version_comp.h"
 
@@ -899,9 +902,9 @@
  * onwards the filename returned in DL_info structure from dladdr is
  * an absolute pathname so technically realpath isn't required.
  * On Linux we read the executable name from /proc/self/exe.
- * On *BSD we read the executable name from /proc/curproc/file.
+ * On FreeBSD, we get the executable name via sysctl(3).
  * As a fallback, and for platforms other than Solaris, Linux, and
- * *BSD, we use FindExecName to compute the executable name.
+ * FreeBSD, we use FindExecName to compute the executable name.
  */
 const char*
 SetExecname(char **argv)
@@ -928,13 +931,9 @@
             }
         }
     }
-#elif defined(__linux__) || defined(_ALLBSD_SOURCE)
+#elif defined(__linux__)
     {
-#if defined(_ALLBSD_SOURCE)
-        const char* self = "/proc/curproc/file";
-#else
         const char* self = "/proc/self/exe";
-#endif
         char buf[PATH_MAX+1];
         int len = readlink(self, buf, PATH_MAX);
         if (len >= 0) {
@@ -942,7 +941,17 @@
             exec_path = JLI_StringDup(buf);
         }
     }
-#else /* !__solaris__ && !__linux__ && !_ALLBSD_SOURCE */
+#elif defined(__FreeBSD__)
+    {
+        char buf[PATH_MAX+1];
+        int name[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+        size_t len = sizeof(buf);
+        if (sysctl(name, 4, buf, &len, NULL, 0) == 0 && len > 0) {
+            buf[len] = '\0';
+            exec_path = JLI_StringDup(buf);
+        }
+    }
+#else /* !__sun && !__linux && !__FreeBSD__ */
     {
         /* Not implemented */
     }
