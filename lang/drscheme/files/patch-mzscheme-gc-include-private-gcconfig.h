--- mzscheme/gc/include/private/gcconfig.h.orig	Fri Jul  7 02:38:23 2006
+++ mzscheme/gc/include/private/gcconfig.h	Fri Sep 22 12:45:27 2006
@@ -335,10 +335,14 @@
 #    define X86_64
 #    define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__amd64__)
+#    define X86_64
+#    define mach_type_known
+# endif
 # if defined(FREEBSD) && defined(__sparc__)
 #    define SPARC
 #    define mach_type_known
-#endif
+# endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -1992,6 +1996,17 @@
 #	    define PREFETCH(x) __builtin_prefetch((x), 0, 0)
 #	    define PREFETCH_FOR_WRITE(x) __builtin_prefetch((x), 1)
 #	endif
+#   endif
+#   ifdef FREEBSD
+#       define OS_TYPE "FREEBSD"
+#       define SIG_SUSPEND SIGUSR1
+#       define SIG_THR_RESTART SIGUSR2
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
+#       define HEURISTIC2
+        extern char etext[];
+#       define SEARCH_FOR_DATA_START
 #   endif
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
