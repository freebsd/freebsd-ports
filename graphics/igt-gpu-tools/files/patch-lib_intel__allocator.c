--- lib/intel_allocator.c.orig	2022-08-31 20:00:01 UTC
+++ lib/intel_allocator.c
@@ -17,6 +17,10 @@
 #include "intel_allocator.h"
 #include "intel_allocator_msgchannel.h"
 
+#ifdef __FreeBSD__
+#define	gettid()	getpid()
+#endif
+
 //#define ALLOCDBG
 #ifdef ALLOCDBG
 #define alloc_info igt_info
