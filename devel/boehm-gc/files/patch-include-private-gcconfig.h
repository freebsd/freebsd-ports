--- include/private/gcconfig.h.orig	Wed Dec 29 22:30:21 2004
+++ include/private/gcconfig.h	Wed Dec 29 22:30:39 2004
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
@@ -1942,6 +1946,12 @@
 #	define HEURISTIC2
 	extern char etext[];
 #	define SEARCH_FOR_DATA_START
+#   endif
+#   ifdef FREEBSD
+#     define OS_TYPE "FREEBSD"
+#     ifdef __ELF__
+#         define DYNAMIC_LOADING
+#     endif
 #   endif
 # endif
 
