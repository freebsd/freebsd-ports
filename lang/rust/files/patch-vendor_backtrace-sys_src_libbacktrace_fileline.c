This file is in the public domain.

--- vendor/backtrace-sys/src/libbacktrace/fileline.c.orig	2019-01-16 09:30:44 UTC
+++ vendor/backtrace-sys/src/libbacktrace/fileline.c
@@ -39,8 +39,39 @@ POSSIBILITY OF SUCH DAMAGE.  */
 #include <stdlib.h>
 #include <unistd.h>
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/sysctl.h>
+#include <limits.h>
+#endif
+
 #include "backtrace.h"
 #include "internal.h"
+
+#if !defined(HAVE_GETEXECNAME) && defined(KERN_PROC_PATHNAME)
+/* Return pathname of executable or 0 on failure. */
+#define HAVE_GETEXECNAME
+static char execname[PATH_MAX + 1];
+static const char *
+getexecname(void)
+{
+  size_t path_len = sizeof(execname);
+  int mib[] = {
+    CTL_KERN,
+#if defined(__NetBSD__)
+    KERN_PROC_ARGS,
+    -1,
+    KERN_PROC_PATHNAME,
+#else
+    KERN_PROC,
+    KERN_PROC_PATHNAME,
+    -1,
+#endif
+  };
+  u_int miblen = sizeof(mib) / sizeof(mib[0]);
+  int rc = sysctl(mib, miblen, execname, &path_len, NULL, 0);
+  return rc ? NULL : execname;
+}
+#endif /* !HAVE_GETEXECNAME && KERN_PROC_PATHNAME */
 
 #ifndef HAVE_GETEXECNAME
 #define getexecname() NULL
