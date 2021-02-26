--- glib/gspawn.c.orig	2020-12-17 03:47:11.474608400 -0800
+++ glib/gspawn.c	2021-02-17 13:58:15.271434000 -0800
@@ -51,6 +51,12 @@
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
@@ -1204,6 +1210,33 @@ filename_to_fd (const char *p)
 }
 #endif
 
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
 static int
@@ -1228,6 +1261,12 @@ safe_fdwalk (int (*cb)(void *data, int fd), void *data
   
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
