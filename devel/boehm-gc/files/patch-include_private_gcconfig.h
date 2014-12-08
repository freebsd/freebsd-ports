--- ./include/private/gcconfig.h.orig
+++ ./include/private/gcconfig.h
@@ -169,7 +169,7 @@
 #      define EWS4800
 #    endif
 #    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) \
-        && !defined(OPENBSD)
+        && !defined(OPENBSD) && !defined(FREEBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #        define ULTRIX
 #      else
@@ -1647,6 +1647,26 @@
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
