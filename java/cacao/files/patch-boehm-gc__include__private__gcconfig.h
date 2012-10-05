--- src/mm/boehm-gc/include/private/gcconfig.h.orig	2012-09-03 12:10:00.000000000 -0400
+++ src/mm/boehm-gc/include/private/gcconfig.h	2012-10-05 13:21:12.000000000 -0400
@@ -69,8 +69,9 @@
 /* Determine the machine type: */
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
-#    if !defined(LINUX) && !defined(NETBSD) && !defined(OPENBSD) \
-        && !defined(DARWIN) && !defined(_WIN32) && !defined(__CEGCC__)
+#    if !defined(LINUX) && !defined(FREEBSD) && !defined(NETBSD) \
+        && !defined(OPENBSD) && !defined(DARWIN) && !defined(_WIN32) \
+        && !defined(__CEGCC__)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -366,6 +367,10 @@
 #    define SPARC
 #    define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__arm__)
+#    define ARM32
+#    define mach_type_known
+# endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -843,8 +848,6 @@
 #       ifndef GC_FREEBSD_THREADS
 #           define MPROTECT_VDB
 #       endif
-#       define SIG_SUSPEND SIGUSR1
-#       define SIG_THR_RESTART SIGUSR2
 #       define FREEBSD_STACKBOTTOM
 #       ifdef __ELF__
 #           define DYNAMIC_LOADING
@@ -1032,8 +1035,6 @@
 #   endif
 #   ifdef FREEBSD
 #       define OS_TYPE "FREEBSD"
-#       define SIG_SUSPEND SIGUSR1
-#       define SIG_THR_RESTART SIGUSR2
 #       define FREEBSD_STACKBOTTOM
 #       ifdef __ELF__
 #           define DYNAMIC_LOADING
@@ -1284,9 +1285,6 @@
 #           define SIG_THR_RESTART      (32+5)
             extern int _end[];
 #           define DATAEND (ptr_t)(_end)
-#       else
-#           define SIG_SUSPEND SIGUSR1
-#           define SIG_THR_RESTART SIGUSR2
 #       endif
 #       define FREEBSD_STACKBOTTOM
 #       ifdef __ELF__
@@ -1608,8 +1606,6 @@
 #   ifdef FREEBSD
 #       define OS_TYPE "FREEBSD"
 /* MPROTECT_VDB is not yet supported at all on FreeBSD/alpha. */
-#       define SIG_SUSPEND SIGUSR1
-#       define SIG_THR_RESTART SIGUSR2
 #       define FREEBSD_STACKBOTTOM
 #       ifdef __ELF__
 #           define DYNAMIC_LOADING
@@ -1898,6 +1894,16 @@
 #     define DATAEND ((ptr_t)(&_end))
 #     define DYNAMIC_LOADING
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
@@ -2066,9 +2072,6 @@
 #           define SIG_THR_RESTART      (32+5)
             extern int _end[];
 #           define DATAEND (ptr_t)(_end)
-#       else
-#           define SIG_SUSPEND SIGUSR1
-#           define SIG_THR_RESTART SIGUSR2
 #       endif
 #       define FREEBSD_STACKBOTTOM
 #       ifdef __ELF__
