--- ./code/unix/unix_shared.c.orig	Fri Nov  4 19:32:00 2005
+++ ./code/unix/unix_shared.c	Wed Jun  7 16:52:01 2006
@@ -20,6 +20,7 @@
 ===========================================================================
 */
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <sys/stat.h>
 #include <errno.h>
 #include <stdio.h>
@@ -430,6 +431,12 @@
 // sysconf() in libc, POSIX.1 compliant
 unsigned int Sys_ProcessorCount(void)
 {
-  return sysconf(_SC_NPROCESSORS_ONLN);
+  int mib[2], value, len;
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_NCPU;
+  len = sizeof(value);
+  sysctl(mib, 2, &value, &len, NULL, 0);
+  return (value);
 }
 #endif
