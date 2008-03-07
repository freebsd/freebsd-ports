--- libguile/gc_os_dep.c.orig	2008-02-16 19:50:24.000000000 +0100
+++ libguile/gc_os_dep.c	2008-03-06 16:21:40.000000000 +0100
@@ -115,6 +115,12 @@
 #    define NETBSD
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__sparc__)
+#    define SPARC
+#    define FREEBSD
+#    include <machine/frame.h>
+#    define mach_type_known
+# endif
 # if defined(__NetBSD__) && defined(__powerpc__)
 #    define POWERPC
 #    define NETBSD
@@ -249,7 +255,21 @@
 #    define ARM32
 #    define mach_type_known
 # endif
-# if defined(__alpha) || defined(__alpha__)
+# if defined(__FreeBSD__) && defined(__ia64__)
+#    define FREEBSD
+#    define IA64
+#    define mach_type_known
+# endif
+# if defined(__FreeBSD__) && defined(__amd64__)
+#    define FREEBSD
+#    define AMD64
+#    define mach_type_known
+# endif
+# if defined(__FreeBSD__) && defined(__alpha__)
+#   define FREEBSD
+#   define ALPHA
+#   define mach_type_known
+# elif defined(__alpha) || defined(__alpha__)
 #   define ALPHA
 #   if !defined(LINUX) && !defined (NETBSD)
 #     define OSF1	/* a.k.a Digital Unix */
@@ -701,8 +721,6 @@
 
 # ifdef SPARC
 #   define MACH_TYPE "SPARC"
-#   define ALIGNMENT 4	/* Required by hardware	*/
-#   define ALIGN_DOUBLE
     extern int etext;
 #   ifdef SUNOS5
 #	define OS_TYPE "SUNOS5"
@@ -750,7 +768,6 @@
 # 	define DYNAMIC_LOADING
 #   endif
 #   ifdef DRSNX
-#       define CPP_WORDSZ 32
 #	define OS_TYPE "DRSNX"
 	extern char * GC_SysVGetDataStart();
 	extern int etext;
@@ -1159,6 +1176,13 @@
 #   endif
 # endif
 
+# ifdef AMD64
+#   define MACH_TYPE "AMD64"
+#   define ALIGN_DOUBLE
+#   define ALIGNMENT 8
+#   define USE_GENERIC_PUSH_REGS
+# endif
+
 # ifdef IA64
 #   define MACH_TYPE "IA64"
 #   define ALIGN_DOUBLE
@@ -1504,8 +1528,15 @@
 #   include <setjmp.h>
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) && defined(I386)
 #  include <machine/trap.h>
+#  define ALIGNMENT 4
+#  define CPP_WORDSZ 32
+#endif
+
+#if defined(FREEBSD) && defined(SPARC)
+#  define ALIGNMENT 8
+#  define ALIGN_DOUBLE
 #endif
 
 #ifdef AMIGA
@@ -1537,7 +1568,7 @@
 #endif
 
 #ifdef SUNOS5SIGS
-# include <sys/siginfo.h>
+/*# include <sys/siginfo.h>*/
 # undef setjmp
 # undef longjmp
 # define setjmp(env) sigsetjmp(env, 1)
@@ -1716,11 +1747,13 @@
     /* static */ jmp_buf GC_jmp_buf;
 
     /*ARGSUSED*/
+#if !(defined(FREEBSD) && defined(SPARC))
     static void GC_fault_handler(sig)
     int sig;
     {
         longjmp(GC_jmp_buf, 1);
     }
+#endif
 
 #   ifdef __STDC__
 	typedef void (*handler)(int);
@@ -1728,6 +1761,7 @@
 	typedef void (*handler)();
 #   endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
 #   if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
 	static struct sigaction old_segv_act;
 #	if defined(_sigargs) || defined(HPUX) /* !Irix6.x */
@@ -1736,7 +1770,9 @@
 #   else
         static handler old_segv_handler, old_bus_handler;
 #   endif
+#endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
     static void GC_setup_temporary_fault_handler()
     {
 #	if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
@@ -1773,7 +1809,9 @@
 #	  endif
 #	endif
     }
+#endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
     static void GC_reset_fault_handler()
     {
 #       if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
@@ -1789,8 +1827,10 @@
 #	  endif
 #       endif
     }
+#endif
 
     /* Single argument version, robust against whole program analysis. */
+#if !(defined(FREEBSD) && defined(SPARC))
     static void
     GC_noop1(x)
     word x;
@@ -1798,9 +1838,11 @@
       static VOLATILE word sink;
       sink = x;
     }
+#endif
 
     /* Return the first nonaddressible location > p (up) or 	*/
     /* the smallest location q s.t. [q,p] is addressible (!up).	*/
+#if !(defined(FREEBSD) && defined(SPARC))
     static ptr_t GC_find_limit(p, up)
     ptr_t p;
     GC_bool up;
@@ -1831,6 +1873,7 @@
  	}
 	return(result);
     }
+#endif
 
 # endif
 
