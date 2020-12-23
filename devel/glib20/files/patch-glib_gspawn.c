--- glib/gspawn.c	2018-09-21 12:29:23.000000000 +0300
+++ glib/gspawn.c	2019-07-20 18:05:15.486558000 +0300
@@ -51,6 +51,13 @@
 #include <sys/syscall.h>  /* for syscall and SYS_getdents64 */
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/file.h>
+#endif
+
 #include "gspawn.h"
 #include "gspawn-private.h"
 #include "gthread.h"
@@ -1204,6 +1211,51 @@
 }
 #endif
 
+#ifdef __FreeBSD__
+static int
+fdwalk2(int (*func)(void *, int), void *udata, int *ret) {
+  size_t i, bufsz = 0;
+  struct xfile *xfbuf, *xf;
+  int uret = 0, pid_found = 0;
+  int mib[2] = { CTL_KERN, KERN_FILE };
+  pid_t pid;
+
+  if (NULL == func)
+    return EINVAL;
+
+  if (sysctl (mib, nitems(mib), NULL, &bufsz, NULL, 0) == -1)
+    return (errno);
+  bufsz += 65536;
+  xfbuf = alloca (bufsz);
+  if (xfbuf == NULL)
+    return errno;
+  if (sysctl (mib, 2, xfbuf, &bufsz, NULL, 0) == -1)
+    return errno;
+  bufsz /= sizeof(struct xfile);
+
+  pid = getpid();
+  for (i = 0; i < bufsz; i++) {
+    xf = &xfbuf[i];
+    if (pid != xf->xf_pid) {
+      if (pid_found) {
+        return 0;
+      } else {
+        continue;
+      }
+    }
+    pid_found = 1;
+    if (0 > xf->xf_fd)
+      continue;
+    uret = func (udata, xf->xf_fd);
+    if (uret != 0)
+      break;
+
+  }
+
+  return 0;
+}
+#endif
+
 /* This function is called between fork() and exec() and hence must be
  * async-signal-safe (see signal-safety(7)). */
 static int
@@ -1228,6 +1280,12 @@
   
 #if 0 && defined(HAVE_SYS_RESOURCE_H)
   struct rlimit rl;
+#endif
+
+#ifdef __FreeBSD__
+  if (fdwalk2(cb, data, &res) == 0)
+      return res;
+  /* If any sysctl/malloc call fails continue with the fall back method */
 #endif
 
 #ifdef __linux__
