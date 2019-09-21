--- base/runtime/include/ml-unixdep.h.orig	2019-06-19 18:37:43 UTC
+++ base/runtime/include/ml-unixdep.h
@@ -37,6 +37,7 @@
  *   INT_GIDLIST		if the second argument to getgroups is int[].
  *   STAT_HAS_TIMESPEC		if the time fields in the "struct stat" type have
  *				type "struct timespec".
+ *   HAS_MKSTEMP		if OS provides the POSIX mkstemp function.
  *
  * Note that only one of the following sets of symbols should be defined:
  *   { HAS_MMAP, HAS_ANON_MMAP, HAS_VM_ALLOCATE }
@@ -94,6 +95,7 @@
 #  define HAS_POLL
 #  define HAS_SIGCONTEXT
 #  define HAS_STRERROR
+#  define HAS_MKSTEMP
 
 /* These declarations are not in <errno.h> */
 extern int	sys_nerr;
@@ -204,6 +206,7 @@ extern char	*sys_errlist[];
 #  define HAS_SIGCONTEXT
 #  define HAS_STRERROR
 #  define STAT_HAS_TIMESPEC
+#  define HAS_MKSTEMP
 
 /* FreeBSD uses MAP_ANON for MAP_ANONYMOUS */
 #  define MAP_ANONYMOUS MAP_ANON
@@ -254,6 +257,16 @@ extern char	*sys_errlist[];
 
 #include <features.h>
 
+#endif
+
+#if defined(OPSYS_FREEBSD)
+#  if defined(INCLUDE_FREEBSD_I386__TYPES)
+#    include <sys/cdefs.h>
+#    include INCLUDE_FREEBSD_I386__TYPES
+#  endif
+#  if defined(INCLUDE_FREEBSD_I386_SIGNAL)
+#    include INCLUDE_FREEBSD_I386_SIGNAL
+#  endif
 #endif
 
 #include <unistd.h>
