--- include/private/gcconfig.h.orig	Thu May  6 08:10:54 2004
+++ include/private/gcconfig.h	Sun Oct 31 02:55:05 2004
@@ -170,7 +170,7 @@
 #   define mach_type_known
 # endif
 # if defined(sparc) && defined(unix) && !defined(sun) && !defined(linux) \
-     && !defined(__OpenBSD__) && !(__NetBSD__)
+     && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 #   define SPARC
 #   define DRSNX
 #   define mach_type_known
@@ -314,6 +314,14 @@
 #    define X86_64
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__amd64__)
+#    define X86_64
+#    define mach_type_known
+#endif
+# if defined(__FreeBSD__) && defined(__sparc__)
+#    define SPARC
+#    define mach_type_known
+#endif
 # if defined(bsdi) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define BSDI
@@ -938,6 +946,23 @@
 #	define DATASTART ((ptr_t)(etext))
 #     endif
 #   endif
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
+#   endif
 # endif
 
 # ifdef I386
@@ -1860,6 +1885,15 @@
 #   endif
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
+#	ifdef __ELF__
+#	    define DYNAMIC_LOADING
+#	endif
+#	define HEURISTIC2
+	extern char etext[];
+#	define SEARCH_FOR_DATA_START
+#   endif
+#   ifdef FREEBSD
+#	define OS_TYPE "FREEBSD"
 #	ifdef __ELF__
 #	    define DYNAMIC_LOADING
 #	endif
