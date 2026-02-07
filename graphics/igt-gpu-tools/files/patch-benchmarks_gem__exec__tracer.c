--- benchmarks/gem_exec_tracer.c.orig	2022-08-31 20:00:00 UTC
+++ benchmarks/gem_exec_tracer.c
@@ -41,6 +41,10 @@
 #include "intel_aub.h"
 #include "intel_chipset.h"
 
+#ifdef __FreeBSD__
+#define	_IOC_TYPE(nr)	(((nr) >> 8) & 255)
+#endif
+
 static int (*libc_close)(int fd);
 static int (*libc_ioctl)(int fd, unsigned long request, void *argp);
 
