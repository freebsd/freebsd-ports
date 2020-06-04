--- util/cacheinfo.c.orig	2019-10-17 15:17:44.000000000 -0500
+++ util/cacheinfo.c	2020-01-17 21:13:29.459470000 -0600
@@ -65,25 +65,28 @@ static void sys_cache_info(int *isize, int *dsize)
     g_free(buf);
 }
 
-#elif defined(__APPLE__) \
-      || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__APPLE__)
 # include <sys/sysctl.h>
-# if defined(__APPLE__)
-#  define SYSCTL_CACHELINE_NAME "hw.cachelinesize"
-# else
-#  define SYSCTL_CACHELINE_NAME "machdep.cacheline_size"
-# endif
-
 static void sys_cache_info(int *isize, int *dsize)
 {
     /* There's only a single sysctl for both I/D cache line sizes.  */
     long size;
     size_t len = sizeof(size);
-    if (!sysctlbyname(SYSCTL_CACHELINE_NAME, &size, &len, NULL, 0)) {
+    if (!sysctlbyname("hw.cachelinesize", &size, &len, NULL, 0)) {
         *isize = *dsize = size;
     }
 }
-
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+# include <sys/sysctl.h>
+static void sys_cache_info(int *isize, int *dsize)
+{
+    /* There's only a single sysctl for both I/D cache line sizes.  */
+    int size;
+    size_t len = sizeof(size);
+    if (!sysctlbyname("machdep.cacheline_size", &size, &len, NULL, 0)) {
+        *isize = *dsize = size;
+    }
+}
 #else
 /* POSIX */
 
