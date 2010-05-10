Index: qemu/vl.c
@@ -57,6 +57,8 @@
 #include <sys/stat.h>
 #if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <libutil.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #else
 #include <util.h>
 #endif
@@ -3368,10 +3369,13 @@ static char *find_datadir(const char *ar
     }
 #elif defined(__FreeBSD__)
     {
-        int len;
-        len = readlink("/proc/curproc/file", buf, sizeof(buf) - 1);
-        if (len > 0) {
-            buf[len] = 0;
+        static int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+        size_t len = sizeof(buf) - 1;
+
+        *buf = '\0';
+        if (!sysctl(mib, sizeof(mib)/sizeof(*mib), buf, &len, NULL, 0) &&
+            *buf) {
+            buf[sizeof(buf) - 1] = '\0';
             p = buf;
         }
     }
