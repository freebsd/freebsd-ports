--- libretro-common/rthreads/rthreads.c.orig	2020-03-17 21:58:04 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -58,6 +58,8 @@
 #include <time.h>
 #endif
 
+#include <sys/time.h>
+
 #if defined(VITA) || defined(BSD) || defined(ORBIS)
 #include <sys/time.h>
 #endif
