--- include/private/gcconfig.h.orig	2008-02-20 22:23:00.000000000 +0300
+++ include/private/gcconfig.h	2009-10-20 01:08:38.000000000 +0400
@@ -64,7 +64,7 @@
 /* Determine the machine type: */
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
-#    if !defined(LINUX) && !defined(NETBSD)
+#    if !defined(LINUX) && !defined(NETBSD) && !defined(FREEBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -334,10 +334,26 @@
 #    define X86_64
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__amd64__)
+#    define X86_64
+#    define mach_type_known
+# endif
+# if defined(__FreeBSD__) && defined(__ia64__)
+#    define IA64
+#    define mach_type_known
+# endif
 # if defined(FREEBSD) && defined(__sparc__)
 #    define SPARC
 #    define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__powerpc__)
+#    define POWERPC
+#    define mach_type_known
+# endif
+# if defined(FREEBSD) && defined(__arm__)
+#    define ARM32
+#    define mach_type_known
+# endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -1771,6 +1787,16 @@
 #     define OS_TYPE "MSWINCE"
 #     define DATAEND /* not needed */
 #   endif
+#   ifdef FREEBSD
+#   define ALIGNMENT 4
+#       define OS_TYPE "FREEBSD"
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
+#	define HEURISTIC2
+	extern char etext[];
+#	define SEARCH_FOR_DATA_START
+#   endif
 #   ifdef NOSYS
       /* __data_start is usually defined in the target linker script.  */
       extern int __data_start[];
@@ -1800,6 +1826,7 @@
 #     define OS_TYPE "MSWINCE"
 #     define DATAEND /* not needed */
 #   endif
+		   
 #   ifdef LINUX
 #     define OS_TYPE "LINUX"
 #     define LINUX_STACKBOTTOM
