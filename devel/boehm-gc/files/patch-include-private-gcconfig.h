--- include/private/gcconfig.h.orig	Sat Dec 18 09:20:16 2004
+++ include/private/gcconfig.h	Sun Mar 20 01:37:33 2005
@@ -328,10 +328,18 @@
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
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -811,6 +819,16 @@
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
@@ -1939,6 +1957,15 @@
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
