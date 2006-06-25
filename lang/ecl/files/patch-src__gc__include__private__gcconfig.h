--- ./src/gc/include/private/gcconfig.h.orig	Fri Aug 12 13:26:42 2005
+++ ./src/gc/include/private/gcconfig.h	Sat Jun 24 22:58:57 2006
@@ -318,10 +318,6 @@
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
@@ -330,10 +326,24 @@
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
@@ -979,6 +989,9 @@
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
+#	ifndef GC_FREEBSD_THREADS
+#	    define MPROTECT_VDB
+#	endif
 	extern char etext[];
 	extern char edata[];
 	extern char end[];
@@ -1215,15 +1228,15 @@
 #   endif
 #   ifdef FREEBSD
 #	define OS_TYPE "FREEBSD"
-#	ifndef GC_FREEBSD_THREADS
-#	    define MPROTECT_VDB
-#	endif
 #	define SIG_SUSPEND SIGUSR1
 #	define SIG_THR_RESTART SIGUSR2
 #	define FREEBSD_STACKBOTTOM
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
+#	ifndef GC_FREEBSD_THREADS
+#	    define MPROTECT_VDB
+#	endif
 	extern char etext[];
 	extern char * GC_FreeBSDGetDataStart();
 #	define DATASTART GC_FreeBSDGetDataStart(0x1000, &etext)
@@ -1926,6 +1939,23 @@
 #	    define PREFETCH(x) __builtin_prefetch((x), 0, 0)
 #	    define PREFETCH_FOR_WRITE(x) __builtin_prefetch((x), 1)
 #	endif
+#   endif
+#   ifdef FREEBSD
+#	define OS_TYPE "FREEBSD"
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
 #   endif
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
