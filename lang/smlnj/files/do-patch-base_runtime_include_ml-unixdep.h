--- base/runtime/include/ml-unixdep.h.orig	2014-08-17 21:09:56.000000000 +0200
+++ base/runtime/include/ml-unixdep.h	2014-08-23 22:24:36.475122070 +0200
@@ -33,6 +33,7 @@
  *   HAS_UCONTEXT		if signal handlers have a ucontext_t argument.
  *   HAS_STRERROR		if the system provides the ISO C strerror function.
  *   INT_GIDLIST		if the second argument to getgroups is int[].
+ *   HAS_MKSTEMP		if OS provides the POSIX mkstemp function.
  *
  * Note that only one of the following sets of symbols should be defined:
  *   { HAS_MMAP, HAS_ANON_MMAP, HAS_VM_ALLOCATE }
@@ -295,6 +296,7 @@
 #  define HAS_ILOGB
 #  define HAS_SIGCONTEXT
 #  define HAS_STRERROR
+#  define HAS_MKSTEMP
 
 /* FreeBSD uses MAP_ANON for MAP_ANONYMOUS */
 #  define MAP_ANONYMOUS MAP_ANON
@@ -377,6 +379,15 @@
 #  define __EXTENSIONS__
 #endif
 
+#if defined(OPSYS_FREEBSD)
+#  if defined(INCLUDE_FREEBSD_I386__TYPES)
+#    include <sys/cdefs.h>
+#    include INCLUDE_FREEBSD_I386__TYPES
+#  endif
+#  if defined(INCLUDE_FREEBSD_I386_SIGNAL)
+#    include INCLUDE_FREEBSD_I386_SIGNAL
+#  endif
+#endif
 #include INCLUDE_TYPES_H
 #include <unistd.h>
 #include <string.h>
