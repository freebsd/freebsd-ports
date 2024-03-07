--- glib/glib-unix.c.orig	2024-03-07 21:35:05 UTC
+++ glib/glib-unix.c
@@ -55,6 +55,11 @@
 #include <sys/syscall.h>  /* for syscall and SYS_getdents64 */
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
 #endif /* HAVE_SYS_RESOURCE_H */
@@ -620,6 +625,33 @@ filename_to_fd (const char *p)
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
 static int safe_fdwalk_with_invalid_fds (int (*cb)(void *data, int fd), void *data);
 
 /* This function is called between fork() and exec() and hence must be
@@ -640,6 +672,13 @@ safe_fdwalk (int (*cb)(void *data, int fd), void *data
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
