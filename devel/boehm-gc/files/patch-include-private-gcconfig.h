--- include/private/gcconfig.h.orig	2012-07-25 15:03:15.000000000 +0300
+++ include/private/gcconfig.h	2012-07-25 15:07:05.000000000 +0300
@@ -73,7 +73,8 @@
 # if defined(__arm) || defined(__arm__) || defined(__thumb__)
 #    define ARM32
 #    if !defined(LINUX) && !defined(NETBSD) && !defined(OPENBSD) \
-        && !defined(DARWIN) && !defined(_WIN32) && !defined(__CEGCC__)
+        && !defined(DARWIN) && !defined(_WIN32) && !defined(__CEGCC__) \
+        && !defined(FREEBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -359,10 +360,18 @@
 #   define I386
 #   define mach_type_known
 # endif
-# if defined(FREEBSD) && defined(__x86_64__)
+# if defined(FREEBSD) && defined(__amd64__)
 #   define X86_64
 #   define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__ia64__)
+#   define IA64
+#   define mach_type_known
+# endif
+# if defined(FREEBSD) && defined(__arm__)
+#   define ARM32
+#   define mach_type_known
+# endif
 # if defined(__NetBSD__) && (defined(i386) || defined(__i386__))
 #   define I386
 #   define mach_type_known
@@ -1949,6 +1958,16 @@
 #     define OS_TYPE "MSWINCE"
 #     define DATAEND /* not needed */
 #   endif
+#   ifdef FREEBSD
+#   define ALIGNMENT 4
+#       define OS_TYPE "FREEBSD"
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
+#      define HEURISTIC2
+       extern char etext[];
+#      define SEARCH_FOR_DATA_START
+#   endif
 #   ifdef DARWIN
       /* iPhone */
 #     define OS_TYPE "DARWIN"
