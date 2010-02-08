--- a/cache-utils.c
+++ b/cache-utils.c
@@ -57,6 +57,23 @@
 }
 #endif
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+static void ppc_init_cacheline_sizes(void)
+{
+    size_t len = 4;
+    unsigned cacheline;
+
+    sysctlbyname ("machdep.cacheline_size", &cacheline, &len, NULL, 0);
+
+    qemu_cache_conf.dcache_bsize = cacheline;
+    qemu_cache_conf.icache_bsize = cacheline;
+}
+#endif    
+
 #ifdef __linux__
 void qemu_cache_utils_init(char **envp)
 {
