--- libgc/include/private/gcconfig.h.orig	Mon Oct  6 22:38:35 2003
+++ libgc/include/private/gcconfig.h	Mon Oct  6 22:38:56 2003
@@ -1151,8 +1151,8 @@
 #	ifndef GC_FREEBSD_THREADS
 #	    define MPROTECT_VDB
 #	endif
-#	define SIG_SUSPEND SIGUSR1
-#	define SIG_THR_RESTART SIGUSR2
+#	define SIG_SUSPEND SIGTSTP
+#	define SIG_THR_RESTART SIGCONT
 #	define FREEBSD_STACKBOTTOM
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
@@ -1466,8 +1466,8 @@
 #   ifdef FREEBSD
 #	define OS_TYPE "FREEBSD"
 /* MPROTECT_VDB is not yet supported at all on FreeBSD/alpha. */
-#	define SIG_SUSPEND SIGUSR1
-#	define SIG_THR_RESTART SIGUSR2
+#	define SIG_SUSPEND SIGTSTP
+#	define SIG_THR_RESTART SIGCONT
 #	define FREEBSD_STACKBOTTOM
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
