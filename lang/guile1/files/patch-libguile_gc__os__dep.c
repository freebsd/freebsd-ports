--- libguile/gc_os_dep.c.orig	2010-12-13 17:25:01 UTC
+++ libguile/gc_os_dep.c
@@ -115,6 +115,12 @@ typedef int GC_bool;
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
@@ -249,7 +255,21 @@ typedef int GC_bool;
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
@@ -701,8 +721,6 @@ scm_get_stack_base ()
 
 # ifdef SPARC
 #   define MACH_TYPE "SPARC"
-#   define ALIGNMENT 4	/* Required by hardware	*/
-#   define ALIGN_DOUBLE
     extern int etext;
 #   ifdef SUNOS5
 #	define OS_TYPE "SUNOS5"
@@ -757,7 +775,6 @@ scm_get_stack_base ()
 # 	define DYNAMIC_LOADING
 #   endif
 #   ifdef DRSNX
-#       define CPP_WORDSZ 32
 #	define OS_TYPE "DRSNX"
 	extern char * GC_SysVGetDataStart();
 	extern int etext;
@@ -1172,6 +1189,13 @@ scm_get_stack_base ()
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
@@ -1517,8 +1541,15 @@ scm_get_stack_base ()
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
@@ -1550,7 +1581,7 @@ scm_get_stack_base ()
 #endif
 
 #ifdef SUNOS5SIGS
-# include <sys/siginfo.h>
+/*# include <sys/siginfo.h>*/
 # undef setjmp
 # undef longjmp
 # define setjmp(env) sigsetjmp(env, 1)
@@ -1729,11 +1760,13 @@ void *scm_get_stack_base()
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
@@ -1741,6 +1774,7 @@ void *scm_get_stack_base()
 	typedef void (*handler)();
 #   endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
 #   if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
 	static struct sigaction old_segv_act;
 #	if defined(_sigargs) || defined(HPUX) /* !Irix6.x */
@@ -1749,7 +1783,9 @@ void *scm_get_stack_base()
 #   else
         static handler old_segv_handler, old_bus_handler;
 #   endif
+#endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
     static void GC_setup_temporary_fault_handler()
     {
 #	if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
@@ -1786,7 +1822,9 @@ void *scm_get_stack_base()
 #	  endif
 #	endif
     }
+#endif
 
+#if !(defined(FREEBSD) && defined(SPARC))
     static void GC_reset_fault_handler()
     {
 #       if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1)
@@ -1802,8 +1840,10 @@ void *scm_get_stack_base()
 #	  endif
 #       endif
     }
+#endif
 
     /* Single argument version, robust against whole program analysis. */
+#if !(defined(FREEBSD) && defined(SPARC))
     static void
     GC_noop1(x)
     word x;
@@ -1811,9 +1851,11 @@ void *scm_get_stack_base()
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
@@ -1844,6 +1886,7 @@ void *scm_get_stack_base()
  	}
 	return(result);
     }
+#endif
 
 # endif
 
