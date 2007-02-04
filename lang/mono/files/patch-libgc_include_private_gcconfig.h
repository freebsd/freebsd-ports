--- libgc/include/private/gcconfig.h.orig	Wed Jul  5 17:55:42 2006
+++ libgc/include/private/gcconfig.h	Sun Sep 10 10:36:31 2006
@@ -347,6 +347,10 @@
 #   define I386
 #   define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__x86_64__)
+#   define X86_64
+#   define mach_type_known
+# endif
 # if defined(__NetBSD__) && (defined(i386) || defined(__i386__))
 #   define I386
 #   define mach_type_known
@@ -1988,6 +1992,22 @@
 #	    define PREFETCH(x) __builtin_prefetch((x), 0, 0)
 #	    define PREFETCH_FOR_WRITE(x) __builtin_prefetch((x), 1)
 #	endif
+#   endif
+#   ifdef FREEBSD
+#       define OS_TYPE "FREEBSD"
+#       ifndef GC_FREEBSD_THREADS
+#           define MPROTECT_VDB
+#       endif
+#       define SIG_SUSPEND SIGTSTP
+#       define SIG_THR_RESTART SIGCONT
+#       define FREEBSD_STACKBOTTOM
+#	define NEED_FIND_LIMIT
+#       ifdef __ELF__
+#           define DYNAMIC_LOADING
+#       endif
+        extern char etext[];
+        extern char * GC_FreeBSDGetDataStart();
+#       define DATASTART GC_FreeBSDGetDataStart(0x1000, &etext)
 #   endif
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
