--- libiberty/getpwd.c.orig	Fri Jan 30 22:18:02 2004
+++ libiberty/getpwd.c	Thu Mar 18 14:24:28 2004
@@ -32,9 +32,9 @@
 #ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
 #endif
-#if HAVE_SYS_STAT_H
+//#if HAVE_SYS_STAT_H
 #include <sys/stat.h>
-#endif
+//#endif
 #if HAVE_LIMITS_H
 #include <limits.h>
 #endif
