--- stub/linux.hh.orig	Wed Jan  5 14:42:03 2005
+++ stub/linux.hh	Wed Jan  5 14:43:40 2005
@@ -35,6 +35,19 @@
 //
 **************************************************************************/
 
+#if defined(__FreeBSD__)
+
+#include <sys/types.h>
+#include <sys/mman.h>
+#include <sys/time.h>
+#include <sys/wait.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <time.h>
+#include <unistd.h>
+
+#else
+
 // <stddef.h>
 typedef long ptrdiff_t;
 typedef unsigned long size_t;
@@ -412,6 +425,7 @@
 #define PT_INTERP       3
 #define PT_PHDR         6
 
+#endif /* __FreeBSD__ */
 
 /*************************************************************************
 // UPX stuff
