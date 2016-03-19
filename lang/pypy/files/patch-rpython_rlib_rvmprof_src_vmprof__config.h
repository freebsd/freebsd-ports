--- rpython/rlib/rvmprof/src/vmprof_config.h.orig	2016-03-19 14:27:46 UTC
+++ rpython/rlib/rvmprof/src/vmprof_config.h
@@ -1,6 +1,6 @@
 #define HAVE_SYS_UCONTEXT_H
 #if defined(__FreeBSD__) || defined(__APPLE__)
-#define PC_FROM_UCONTEXT uc_mcontext.mc_rip
+#define PC_FROM_UCONTEXT uc_mcontext.mc_eip
 #else
 #define PC_FROM_UCONTEXT uc_mcontext.gregs[REG_RIP]
 #endif
