--- include/private/gcconfig.h.orig	2014-06-03 06:08:02 UTC
+++ include/private/gcconfig.h
@@ -97,7 +97,7 @@
 # endif
 # if defined(__aarch64__)
 #    define AARCH64
-#    if !defined(LINUX)
+#    if !defined(LINUX) && !defined(FREEBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -169,7 +169,7 @@
 #      define EWS4800
 #    endif
 #    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) \
-        && !defined(OPENBSD)
+        && !defined(OPENBSD) && !defined(FREEBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #        define ULTRIX
 #      else
@@ -402,6 +402,10 @@
 #   define I386
 #   define mach_type_known
 # endif
+# if defined(FREEBSD) && defined(__aarch64__)
+#   define AARCH64
+#   define mach_type_known
+# endif
 # if defined(FREEBSD) && (defined(__amd64__) || defined(__x86_64__))
 #   define X86_64
 #   define mach_type_known
@@ -1647,6 +1651,26 @@
 #    define DATAEND ((ptr_t)(&_end))
 #    define DYNAMIC_LOADING
 #  endif
+#  ifdef FREEBSD
+#    define OS_TYPE "FREEBSD"
+#    define ALIGNMENT 4
+#    define SIG_SUSPEND SIGUSR1
+#    define SIG_THR_RESTART SIGUSR2
+#    define FREEBSD_STACKBOTTOM
+#    ifdef __ELF__
+#        define DYNAMIC_LOADING
+#    endif
+     extern char etext[];
+     extern char edata[];
+     extern char end[];
+#    define NEED_FIND_LIMIT
+#    define DATASTART ((ptr_t)(&etext))
+     ptr_t GC_find_limit(ptr_t, GC_bool);
+#    define DATAEND (GC_find_limit (DATASTART, TRUE))
+#    define DATAEND_IS_FUNC
+#    define DATASTART2 ((ptr_t)(&edata))
+#    define DATAEND2 ((ptr_t)(&end))
+#  endif
 #  if defined(NONSTOP)
 #    define CPP_WORDSZ 32
 #    define OS_TYPE "NONSTOP"
@@ -1998,6 +2022,20 @@
       extern char _end[];
 #     define DATAEND ((ptr_t)(&_end))
 #   endif
+#   ifdef FREEBSD
+#     define OS_TYPE "FREEBSD"
+#     ifndef GC_FREEBSD_THREADS
+#       define MPROTECT_VDB
+#     endif
+#     define FREEBSD_STACKBOTTOM
+#     ifdef __ELF__
+#       define DYNAMIC_LOADING
+#     endif
+      extern char etext[];
+      ptr_t GC_FreeBSDGetDataStart(size_t, ptr_t);
+#     define DATASTART GC_FreeBSDGetDataStart(0x1000, (ptr_t)etext)
+#     define DATASTART_IS_FUNC
+#   endif
 #   ifdef NOSYS
       /* __data_start is usually defined in the target linker script.   */
       extern int __data_start[];
