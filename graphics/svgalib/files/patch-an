--- src/vgamisc.c.orig	Tue Jul 27 19:36:19 1999
+++ src/vgamisc.c	Wed Aug 30 17:58:13 2000
@@ -73,8 +73,8 @@
     return __svgalib_graph_mem;
 }
 
-#include <syscall.h>
-#include <linux/kernel.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 int __svgalib_physmem(void)
 {
@@ -82,10 +82,11 @@
     printf("__svgalib_physmem: are you sure you wanna do this??\n");
     return -1;
 #else
-    struct sysinfo si;
-    si.totalram = 0;
-    syscall(SYS_sysinfo, &si);
-    return si.totalram;
+    int mem;
+    int smem;
+    smem = sizeof(mem);
+    sysctlbyname("hw.physmem", &mem, &smem, NULL, 0);
+    return mem;
 #endif
 }
 
