--- utils/mono-state.c.orig	2019-05-24 22:08:27.154445000 -0400
+++ mono/utils/mono-state.c	2019-05-24 22:08:47.363559000 -0400
@@ -36,6 +36,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#ifdef HAVE_SYS_STAT_H
+#include <sys/stat.h>
+#endif
+
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
