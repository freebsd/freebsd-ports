--- rpython/rlib/rvmprof/src/shared/vmprof_unix.h.orig	2018-07-19 09:03:21 UTC
+++ rpython/rlib/rvmprof/src/shared/vmprof_unix.h
@@ -24,6 +24,9 @@
 
 #include "vmprof_mt.h"
 
+#ifdef __FreeBSD__
+#include <ucontext.h>
+#endif
 #include <signal.h>
 
 RPY_EXTERN void vmprof_ignore_signals(int ignored);
