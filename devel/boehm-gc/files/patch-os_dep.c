--- os_dep.c.orig	Thu Jul  8 04:16:28 2004
+++ os_dep.c	Sun Oct 31 02:13:04 2004
@@ -2372,7 +2372,7 @@
 #   endif
 #   ifdef FREEBSD
 #     define SIG_OK (sig == SIGBUS)
-#     define CODE_OK (code == BUS_PAGE_FAULT)
+#     define CODE_OK TRUE
 #   endif
 # endif /* SUNOS4 || (FREEBSD && !SUNOS5SIGS) */
 
@@ -3943,7 +3943,11 @@
 #	 if defined(OPENBSD) || defined(NETBSD)
 #	   include <frame.h>
 #	 else
-#	   include <sys/frame.h>
+#	   if defined(FREEBSD)
+#	     include <machine/frame.h>
+#	   else
+#	     include <sys/frame.h>
+#	   endif
 #	 endif
 #      endif
 #    endif
@@ -3989,7 +3993,7 @@
 
 #else /* No builtin backtrace; do it ourselves */
 
-#if (defined(OPENBSD) || defined(NETBSD)) && defined(SPARC)
+#if (defined(OPENBSD) || defined(NETBSD) || defined(FREEBSD)) && defined(SPARC)
 #  define FR_SAVFP fr_fp
 #  define FR_SAVPC fr_pc
 #else
