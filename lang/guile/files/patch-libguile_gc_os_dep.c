--- libguile/gc_os_dep.c.orig	Sat May  3 23:15:57 2003
+++ libguile/gc_os_dep.c	Sat May  3 23:26:25 2003
@@ -93,6 +93,11 @@
 #    define OPENBSD
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__sparc__)
+#    define SPARC
+#    define FREEBSD
+#    define mach_type_known
+# endif
 # if defined(__NetBSD__) && defined(__powerpc__)
 #    define POWERPC
 #    define NETBSD
@@ -225,7 +230,11 @@
 #    define ARM32
 #    define mach_type_known
 # endif
-# if defined(__alpha) || defined(__alpha__)
+# if defined(__FreeBSD__) && defined(__alpha__)
+#   define FREEBSD
+#   define ALPHA
+#   define mach_type_known
+# elif defined(__alpha) || defined(__alpha__)
 #   define ALPHA
 #   if !defined(LINUX)
 #     define OSF1	/* a.k.a Digital Unix */
@@ -1468,7 +1477,7 @@
 #   include <setjmp.h>
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) && defined(I386)
 #  include <machine/trap.h>
 #endif
 
