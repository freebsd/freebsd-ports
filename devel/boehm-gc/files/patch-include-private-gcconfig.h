--- include/private/gcconfig.h.orig	Sat Dec 18 09:20:16 2004
+++ include/private/gcconfig.h	Mon Jan  3 19:49:44 2005
@@ -328,6 +328,10 @@
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
@@ -1939,6 +1943,15 @@
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
