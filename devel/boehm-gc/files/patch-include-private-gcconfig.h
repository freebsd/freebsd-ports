--- include/private/gcconfig.h.orig	Tue Jun 17 04:01:23 2003
+++ include/private/gcconfig.h	Wed May  5 14:35:44 2004
@@ -306,6 +306,10 @@
 #   define I386
 #   define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__amd64__)
+#    define X86_64
+#    define mach_type_known
+# endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -1793,6 +1797,13 @@
 	  __asm__ __volatile__ ("	prefetch	%0": : "m"(*(char *)(x)))
 #	define PREFETCH_FOR_WRITE(x) \
 	  __asm__ __volatile__ ("	prefetchw	%0": : "m"(*(char *)(x)))
+#   endif
+#   ifdef FREEBSD
+#	define OS_TYPE "FREEBSD"
+#	define DYNAMIC_LOADING
+#	define HEURISTIC2
+	extern char etext[];
+#	define SEARCH_FOR_DATA_START
 #   endif
 # endif
 
