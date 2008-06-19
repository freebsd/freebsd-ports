--- mzscheme/gc2/sighand.c.orig	2007-04-29 04:08:24.000000000 +0200
+++ mzscheme/gc2/sighand.c	2008-06-19 04:36:23.000000000 +0200
@@ -27,13 +27,18 @@
 /*  As of 2007/04/28, this is a guess for NetBSD and OpenBSD!  */
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 # include <signal.h>
+# include <sys/param.h>
 void fault_handler(int sn, siginfo_t *si, void *ctx)
 {
   if (!designate_modified(si->si_addr))
     abort();
 }
 #  define NEED_SIGACTION
-#  define USE_SIGACTON_SIGNAL_KIND SIGBUS
+#  if defined(__FreeBSD__) && (__FreeBSD_version < 700000)
+#    define USE_SIGACTON_SIGNAL_KIND SIGBUS
+#  else
+#    define USE_SIGACTON_SIGNAL_KIND SIGSEGV
+#  endif
 #endif
 
 /* ========== Solaris signal handler ========== */
