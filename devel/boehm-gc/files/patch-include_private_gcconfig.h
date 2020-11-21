--- include/private/gcconfig.h.orig	2020-11-21 06:02:51 UTC
+++ include/private/gcconfig.h
@@ -239,7 +239,7 @@ EXTERN_C_BEGIN
 #      define EWS4800
 #    endif
 #    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) \
-        && !defined(OPENBSD)
+        && !defined(OPENBSD) && !defined(FREEBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #        define ULTRIX
 #      else
@@ -670,7 +670,7 @@ EXTERN_C_BEGIN
 #   endif
 #   define mach_type_known
 # endif
-# if defined(__riscv) && defined(LINUX)
+# if defined(__riscv)
 #   define RISCV
 #   define mach_type_known
 # endif
@@ -2883,6 +2883,19 @@ EXTERN_C_BEGIN
 #     define DATASTART ((ptr_t)__data_start)
 #     define LINUX_STACKBOTTOM
 #     define DYNAMIC_LOADING
+#   endif
+#   ifdef FREEBSD
+#     define OS_TYPE "FREEBSD"
+#     ifndef GC_FREEBSD_THREADS
+#       define MPROTECT_VDB
+#     endif
+#     define SIG_SUSPEND SIGUSR1
+#     define SIG_THR_RESTART SIGUSR2
+#     define FREEBSD_STACKBOTTOM
+#     define DYNAMIC_LOADING
+      extern char etext[];
+#     define DATASTART GC_FreeBSDGetDataStart(0x1000, (ptr_t)etext)
+#     define DATASTART_USES_BSDGETDATASTART
 #   endif
 # endif /* RISCV */
 
