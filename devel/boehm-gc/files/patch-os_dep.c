--- os_dep.c.orig	Thu Jul  8 04:16:28 2004
+++ os_dep.c	Fri Dec 17 03:29:13 2004
@@ -700,7 +700,7 @@
     || defined(HURD) || defined(NETBSD)
 	static struct sigaction old_segv_act;
 #	if defined(_sigargs) /* !Irix6.x */ || defined(HPUX) \
-	|| defined(HURD) || defined(NETBSD)
+	|| defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	    static struct sigaction old_bus_act;
 #	endif
 #   else
@@ -715,7 +715,7 @@
 #   endif
     {
 #	if defined(SUNOS5SIGS) || defined(IRIX5)  \
-        || defined(OSF1) || defined(HURD) || defined(NETBSD)
+        || defined(OSF1) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	  struct sigaction	act;
 
 	  act.sa_handler	= h;
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
