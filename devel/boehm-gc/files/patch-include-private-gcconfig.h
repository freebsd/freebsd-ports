--- include/private/gcconfig.h.orig	Sat May 21 05:48:29 2005
+++ include/private/gcconfig.h	Thu Jun 30 01:10:10 2005
@@ -62,7 +62,7 @@
 /* Determine the machine type: */
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
-#    if !defined(LINUX) && !defined(NETBSD)
+#    if !defined(LINUX) && !defined(NETBSD) && !defined(FREEBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -330,10 +330,22 @@
 #    define X86_64
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__amd64__)
+#    define X86_64
+#    define mach_type_known
+# endif
 # if defined(FREEBSD) && defined(__sparc__)
 #    define SPARC
 #    define mach_type_known
-#endif
+# endif
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
@@ -822,6 +834,16 @@
 #     define DATASTART GC_data_start
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
 #     define ALIGNMENT 4
 #     define OS_TYPE "NOSYS"
@@ -1782,6 +1804,17 @@
 #	endif
 #       define USE_GENERIC_PUSH_REGS
 #   endif
+#   ifdef FREEBSD
+#   define ALIGNMENT 4
+#       define OS_TYPE "FREEBSD"
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
+#       define HEURISTIC2
+	extern char etext[];
+#       define SEARCH_FOR_DATA_START
+#   endif
+		   
 #   ifdef LINUX
 #       define OS_TYPE "LINUX"
 #       define HEURISTIC1
@@ -1932,6 +1965,15 @@
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
+#	define HEURISTIC2
+	extern char etext[];
+#	define SEARCH_FOR_DATA_START
+#   endif
+#   ifdef FREEBSD
+#       define OS_TYPE "FREEBSD"
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
 #	define HEURISTIC2
 	extern char etext[];
 #	define SEARCH_FOR_DATA_START
