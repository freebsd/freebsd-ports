--- base/runtime/include/ml-unixdep.h.orig	2019-11-14 19:24:04 UTC
+++ base/runtime/include/ml-unixdep.h
@@ -33,9 +33,10 @@
  *   HAS_UCONTEXT		if signal handlers have a ucontext_t argument.
  *   HAS_STRERROR		if the system provides the ISO C strerror function.
  *   INT_GIDLIST		if the second argument to getgroups is int[].
+ *   HAS_MKSTEMP		if OS provides the POSIX mkstemp function.
  *   STAT_HAS_TIMESPEC		if the time fields in the "struct stat" type have
  *				type "struct timespec".
- *   HAS_NANOSLEEP              if the system provides the nanosleep(2) function.
+ *   HAS_NANOSLEEP		if the system provides the nanosleep(2) function.
  *
  * Note that only one of the following sets of symbols should be defined:
  *   { HAS_MMAP, HAS_ANON_MMAP, HAS_VM_ALLOCATE }
@@ -208,8 +209,11 @@ extern char	*sys_errlist[];
 #  define HAS_SELECT
 #  define HAS_UCONTEXT
 #  define HAS_STRERROR
+#  define HAS_MKSTEMP
 #  define STAT_HAS_TIMESPEC
 #  define HAS_NANOSLEEP
+/* FreeBSD uses MAP_ANON for MAP_ANONYMOUS */
+#  define MAP_ANONYMOUS MAP_ANON
 
 #elif defined(OPSYS_NETBSD) /* version 3.x */
 #  define OS_NAME	"BSD"
