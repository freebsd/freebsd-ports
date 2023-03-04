--- glib/gspawn.c.orig	2023-03-10 14:33:15 UTC
+++ glib/gspawn.c
@@ -54,6 +54,12 @@
 #include <sys/syscall.h>  /* for syscall and SYS_getdents64 */
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 #include "gspawn.h"
 #include "gspawn-private.h"
 #include "gthread.h"
@@ -1231,6 +1237,33 @@ g_spawn_check_exit_status (gint      wait_status,
   return g_spawn_check_wait_status (wait_status, error);
 }
 
+#ifdef __FreeBSD__
+static int
+fdwalk2(int (*func)(void *, int), void *udata, gint *ret)
+{
+  struct kinfo_file *kf;
+  int i, cnt;
+
+  if (NULL == func)
+    return EINVAL;
+
+  kf = kinfo_getfile(getpid(), &cnt);
+  if (kf == NULL)
+    return ENOMEM;
+
+  for (i = 0; i < cnt; i++) {
+    if (0 > kf[i].kf_fd)
+      continue;
+    *ret = func (udata, kf[i].kf_fd);
+    if (*ret != 0)
+      break;
+  }
+
+  free(kf);
+  return 0;
+}
+#endif
+
 /* This function is called between fork() and exec() and hence must be
  * async-signal-safe (see signal-safety(7)). */
 static gssize
@@ -1432,6 +1465,13 @@ safe_fdwalk (int (*cb)(void *data, int fd), void *data
    * may fail on non-Linux operating systems. See safe_fdwalk_with_invalid_fds
    * for a slower alternative.
    */
+
+#ifdef __FreeBSD__
+  gint res = 0;
+  if (fdwalk2(cb, data, &res) == 0)
+      return res;
+  /* If any sysctl/malloc call fails continue with the fall back method */
+#endif
 
 #ifdef __linux__
   gint fd;
