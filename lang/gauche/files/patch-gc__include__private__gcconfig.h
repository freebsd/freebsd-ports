--- ./gc/include/private/gcconfig.h.orig	Sat Mar  4 12:55:44 2006
+++ ./gc/include/private/gcconfig.h	Tue May  9 14:38:56 2006
@@ -62,7 +62,7 @@
 /* Determine the machine type: */
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
-#    if !defined(LINUX) && !defined(NETBSD)
+#    if !defined(LINUX) && !defined(NETBSD) && !defined(FREEBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -335,10 +335,22 @@
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
@@ -853,6 +865,16 @@
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
@@ -1848,6 +1870,17 @@
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
 #       define LINUX_STACKBOTTOM
@@ -1998,6 +2031,17 @@
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
+#	define HEURISTIC2
+	extern char etext[];
+#	define SEARCH_FOR_DATA_START
+#   endif
+#   ifdef FREEBSD
+#       define OS_TYPE "FREEBSD"
+#       define SIG_SUSPEND SIGUSR1
+#       define SIG_THR_RESTART SIGUSR2
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
 #	define HEURISTIC2
 	extern char etext[];
 #	define SEARCH_FOR_DATA_START
