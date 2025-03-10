--- intl/osdep.c.orig	2019-05-11 11:29:32 UTC
+++ intl/osdep.c
@@ -18,6 +18,33 @@
 # include "intl-exports.c"
 #elif defined __EMX__ && !defined __KLIBC__
 # include "os2compat.c"
+#elif defined __FreeBSD__
+#include <config.h>
+#include <osreldate.h>
+#include <dlfcn.h>
+#include <pthread.h>
+static __attribute__((constructor)) void
+libintl_init (void)
+{
+#if __FreeBSD_version >= 1400094
+  /* This dlopen call initialises libpthread if it is present.  Normally
+     this is handled by linking to libpthread but libintl does not link
+     with libpthread to avoid the overhead for non-threaded programs.  */
+  (void) dlopen ("libpthread.so", RTLD_LAZY | RTLD_GLOBAL | RTLD_NOLOAD);
+#else
+  /* The dlopen call above does not work correctly on older versions of
+     FreeBSD.  Call pthread_mutex_timedlock instead.  It initialises
+     libpthread and there's no libc stub that can preempt it.  */
+#pragma weak pthread_mutex_timedlock
+  if (pthread_mutex_timedlock != NULL)
+    {
+      pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
+      pthread_mutex_timedlock (&lock, NULL);
+      pthread_mutex_unlock (&lock);
+      pthread_mutex_destroy (&lock);
+    }
+#endif
+}
 #else
 /* Avoid AIX compiler warning.  */
 typedef int dummy;
