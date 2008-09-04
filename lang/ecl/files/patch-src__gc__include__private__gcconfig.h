--- src/gc/include/private/gcconfig.h.orig	2007-03-28 09:59:40.000000000 +0200
+++ src/gc/include/private/gcconfig.h	2008-08-27 16:27:54.000000000 +0200
@@ -330,10 +330,6 @@
 #   define OPENBSD
 #   define mach_type_known
 # endif
-# if defined(FREEBSD) && (defined(i386) || defined(__i386__))
-#   define I386
-#   define mach_type_known
-# endif
 # if defined(__NetBSD__) && (defined(i386) || defined(__i386__))
 #   define I386
 #   define mach_type_known
@@ -342,10 +338,24 @@
 #    define X86_64
 #    define mach_type_known
 # endif
-# if defined(FREEBSD) && defined(__sparc__)
-#    define SPARC
-#    define mach_type_known
-#endif
+# if defined(FREEBSD)
+#   ifdef __i386__
+#     define I386
+#     define mach_type_known
+#   endif
+#   ifdef __amd64__
+#     define X86_64
+#     define mach_type_known
+#   endif
+#   ifdef __sparc64__
+#     define SPARC
+#     define mach_type_known
+#   endif
+#   ifdef __ia64__
+#     define IA64
+#     define mach_type_known
+#   endif
+# endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -1017,6 +1027,9 @@
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
+#	ifndef GC_FREEBSD_THREADS
+#	    define MPROTECT_VDB
+#	endif
 	extern char etext[];
 	extern char edata[];
 	extern char end[];
@@ -2009,6 +2022,23 @@
 #   endif
 #   ifdef FREEBSD
 #	define OS_TYPE "FREEBSD"
+#	define SIG_SUSPEND SIGUSR1
+#	define SIG_THR_RESTART SIGUSR2
+#	define FREEBSD_STACKBOTTOM
+#	ifdef __ELF__
+#	    define DYNAMIC_LOADING
+#	endif
+	extern char etext[];
+	extern char edata[];
+	extern char end[];
+#	define NEED_FIND_LIMIT
+#	define DATASTART ((ptr_t)(&etext))
+#	define DATAEND (GC_find_limit (DATASTART, TRUE))
+#	define DATASTART2 ((ptr_t)(&edata))
+#	define DATAEND2 ((ptr_t)(&end))
+#   endif
+#   ifdef FREEBSD
+#	define OS_TYPE "FREEBSD"
 #	ifndef GC_FREEBSD_THREADS
 #	    define MPROTECT_VDB
 #	endif
