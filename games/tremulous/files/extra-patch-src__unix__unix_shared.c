--- ./tremulous-1.1.0-src/src/unix/unix_shared.c.orig	Sat Dec 10 17:19:52 2005
+++ ./tremulous-1.1.0-src/src/unix/unix_shared.c	Wed Jun  7 16:59:51 2006
@@ -22,6 +22,7 @@
 */
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include <errno.h>
 #include <stdio.h>
 #include <dirent.h>
@@ -431,6 +432,12 @@
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
