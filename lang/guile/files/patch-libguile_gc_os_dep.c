--- libguile/gc_os_dep.c	2008-02-23 18:14:28.087264270 -0600
+++ libguile/gc_os_dep.c	2008-02-23 18:22:25.194095724 -0600
@@ -115,6 +115,14 @@
 #    define NETBSD
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__sparc__)
+#    define FREEBSD
+#    include <machine/frame.h>
+#    define ALIGNMENT 8
+#    define CPP_WORDSZ 64
+#    define ALIGN_DOUBLE
+#    define mach_type_known
+# endif
 # if defined(__NetBSD__) && defined(__powerpc__)
 #    define POWERPC
 #    define NETBSD
@@ -249,7 +257,21 @@
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
@@ -1159,6 +1181,13 @@
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
@@ -1504,7 +1533,7 @@
 #   include <setjmp.h>
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) && defined(I386)
 #  include <machine/trap.h>
 #endif
 
@@ -1537,7 +1566,7 @@
 #endif
 
 #ifdef SUNOS5SIGS
-# include <sys/siginfo.h>
+/*# include <sys/siginfo.h>*/
 # undef setjmp
 # undef longjmp
 # define setjmp(env) sigsetjmp(env, 1)
Only in guile-1.8.4/libguile: gc_os_dep.c.orig
