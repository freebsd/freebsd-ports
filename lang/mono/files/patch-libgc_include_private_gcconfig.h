--- libgc/include/private/gcconfig.h.orig	Tue Aug  2 17:51:19 2005
+++ libgc/include/private/gcconfig.h	Wed Aug  3 02:05:34 2005
@@ -306,6 +306,10 @@
 #   define I386
 #   define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__x86_64__)
+#    define X86_64
+#    define mach_type_known
+# endif
 # if defined(__NetBSD__) && (defined(i386) || defined(__i386__))
 #   define I386
 #   define mach_type_known
@@ -1859,6 +1863,33 @@
 #	    define PREFETCH_FOR_WRITE(x) __builtin_prefetch((x), 1)
 #	endif
 #   endif
+
+#   ifdef FREEBSD
+#	define OS_TYPE "FREEBSD"
+#	ifndef GC_FREEBSD_THREADS
+#	    define MPROTECT_VDB
+#	endif
+#      define SIG_SUSPEND SIGTSTP
+#      define SIG_THR_RESTART SIGCONT
+#	define FREEBSD_STACKBOTTOM
+#	ifdef __ELF__
+#	    define DYNAMIC_LOADING
+#	endif
+        extern char etext[];
+//        extern char * GC_FreeBSDGetDataStart();
+#       define DATASTART GC_FreeBSDGetDataStart(0x1000, &etext)
+
+//#	define HEURISTIC2
+	extern char etext[];
+//#	define SEARCH_FOR_DATA_START
+
+/*
+	extern char etext[];
+	extern char * GC_FreeBSDGetDataStart();
+#	define DATASTART GC_FreeBSDGetDataStart(0x1000, &etext)
+*/
+#   endif
+
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
 #	ifdef __ELF__
