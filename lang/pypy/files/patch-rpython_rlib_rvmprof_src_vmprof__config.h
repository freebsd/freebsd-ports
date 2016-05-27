--- rpython/rlib/rvmprof/src/vmprof_config.h.orig	2016-05-09 13:03:17 UTC
+++ rpython/rlib/rvmprof/src/vmprof_config.h
@@ -1,5 +1,5 @@
 #define HAVE_SYS_UCONTEXT_H
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
   #ifdef __i386__
     #define PC_FROM_UCONTEXT uc_mcontext.mc_eip
   #else
