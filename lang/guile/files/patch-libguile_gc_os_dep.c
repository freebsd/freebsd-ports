--- libguile/gc_os_dep.c.orig	Wed Apr 16 22:16:21 2003
+++ libguile/gc_os_dep.c	Sun Sep 12 15:18:00 2004
@@ -93,6 +93,14 @@
 #    define OPENBSD
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
@@ -225,7 +233,21 @@
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
 #   if !defined(LINUX)
 #     define OSF1	/* a.k.a Digital Unix */
@@ -1125,6 +1147,13 @@
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
@@ -1468,7 +1497,7 @@
 #   include <setjmp.h>
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) && defined(I386)
 #  include <machine/trap.h>
 #endif
 
@@ -1501,7 +1530,7 @@
 #endif
 
 #ifdef SUNOS5SIGS
-# include <sys/siginfo.h>
+/*# include <sys/siginfo.h>*/
 # undef setjmp
 # undef longjmp
 # define setjmp(env) sigsetjmp(env, 1)
