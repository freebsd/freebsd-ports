--- dbus/dbus-sysdeps-unix.c.orig	2023-08-16 10:29:50 UTC
+++ dbus/dbus-sysdeps-unix.c
@@ -37,6 +37,7 @@
 #include "dbus-credentials.h"
 #include "dbus-nonce.h"
 
+#include <limits.h>
 #include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
@@ -62,6 +63,9 @@
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
+#ifdef HAVE_LINUX_CLOSE_RANGE_H
+#include <linux/close_range.h>
+#endif
 #ifdef HAVE_SYSLOG_H
 #include <syslog.h>
 #endif
@@ -80,6 +84,9 @@
 #ifdef HAVE_SYS_RANDOM_H
 #include <sys/random.h>
 #endif
+#ifdef HAVE_SYS_SYSCALL_H
+#include <sys/syscall.h>
+#endif
 
 #ifdef HAVE_ADT
 #include <bsm/adt.h>
@@ -137,6 +144,21 @@
 
 #endif /* Solaris */
 
+#if defined(__linux__) && defined(__NR_close_range) && !defined(HAVE_CLOSE_RANGE)
+/* The kernel headers are new enough to have the close_range syscall,
+ * but glibc isn't new enough to have the syscall wrapper, so call the
+ * syscall directly. */
+static inline int
+close_range (unsigned int first,
+             unsigned int last,
+             unsigned int flags)
+{
+  return syscall (__NR_close_range, first, last, flags);
+}
+/* Now we can call that inline wrapper as though it was provided by glibc. */
+#define HAVE_CLOSE_RANGE
+#endif
+
 /**
  * Ensure that the standard file descriptors stdin, stdout and stderr
  * are open, by opening /dev/null if necessary.
@@ -4791,7 +4813,24 @@ _dbus_close_all (void)
 void
 _dbus_close_all (void)
 {
+#ifdef HAVE_CLOSE_RANGE
+  if (close_range (3, INT_MAX, 0) == 0)
+    return;
+#endif
+
+  /* Some library implementations of closefrom() are not async-signal-safe,
+   * and we call _dbus_close_all() after forking, so we only do this on
+   * operating systems where we know that closefrom() is a system call */
+#if defined(HAVE_CLOSEFROM) && ( \
+    defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
+    defined(__OpenBSD__) || \
+    defined(__sun__) && defined(F_CLOSEFROM) \
+)
+  closefrom (3);
+#else
   act_on_fds_3_and_up (close_ignore_error);
+#endif
 }
 
 /**
@@ -4801,6 +4840,11 @@ _dbus_fd_set_all_close_on_exec (void)
 void
 _dbus_fd_set_all_close_on_exec (void)
 {
+#if defined(HAVE_CLOSE_RANGE) && defined(CLOSE_RANGE_CLOEXEC)
+  if (close_range (3, INT_MAX, CLOSE_RANGE_CLOEXEC) == 0)
+    return;
+#endif
+
   act_on_fds_3_and_up (_dbus_fd_set_close_on_exec);
 }
 
