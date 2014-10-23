--- src/gallium/auxiliary/util/u_cpu_detect.c.orig	2014-09-19 18:23:33 UTC
+++ src/gallium/auxiliary/util/u_cpu_detect.c
@@ -52,7 +52,7 @@
 #include <machine/cpu.h>
 #endif
 
-#if defined(PIPE_OS_FREEBSD)
+#if defined(PIPE_OS_FREEBSD) || defined(PIPE_OS_DRAGONFLY)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
