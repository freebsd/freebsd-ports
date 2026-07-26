Allow CONFIG_MEMBARRIER on FreeBSD: the meson probe (see
patch-meson.build) can now succeed here, but this file only knew how
to issue the syscall on Linux and hit the #error otherwise. FreeBSD
13+ provides a Linux-compatible membarrier(2) via sys/membarrier.h.

--- util/sys_membarrier.c.orig	2026-06-08 04:08:51 UTC
+++ util/sys_membarrier.c
@@ -10,14 +10,22 @@
 #include "qemu/sys_membarrier.h"
 #include "qemu/error-report.h"
 
+#if defined(CONFIG_LINUX) || defined(__FreeBSD__)
 #ifdef CONFIG_LINUX
 #include <linux/membarrier.h>
+#else
+#include <sys/membarrier.h>
+#endif
 #include <sys/syscall.h>
 
 static int
 membarrier(int cmd, int flags)
 {
+#ifdef CONFIG_LINUX
     return syscall(__NR_membarrier, cmd, flags);
+#else
+    return syscall(SYS_membarrier, cmd, flags);
+#endif
 }
 #endif
 
@@ -25,7 +33,7 @@
 {
 #if defined CONFIG_WIN32
     FlushProcessWriteBuffers();
-#elif defined CONFIG_LINUX
+#elif defined(CONFIG_LINUX) || defined(__FreeBSD__)
     membarrier(MEMBARRIER_CMD_SHARED, 0);
 #else
 #error --enable-membarrier is not supported on this operating system.
@@ -34,7 +42,7 @@
 
 void smp_mb_global_init(void)
 {
-#ifdef CONFIG_LINUX
+#if defined(CONFIG_LINUX) || defined(__FreeBSD__)
     int ret = membarrier(MEMBARRIER_CMD_QUERY, 0);
     if (ret < 0) {
         error_report("This QEMU binary requires the membarrier system call.");
