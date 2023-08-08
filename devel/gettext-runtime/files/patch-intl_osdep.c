--- intl/osdep.c.orig	2019-05-11 11:29:32 UTC
+++ intl/osdep.c
@@ -18,6 +18,25 @@
 # include "intl-exports.c"
 #elif defined __EMX__ && !defined __KLIBC__
 # include "os2compat.c"
+#elif defined __FreeBSD__
+#include <config.h>
+#include <sys/param.h>
+#include <dlfcn.h>
+#include <pthread.h>
+static __attribute__((constructor)) void
+libintl_init (void)
+{
+#if __FreeBSD_version >= 1400094
+  /* We don't link with libpthread in order to avoid the overhead for
+     non-threaded programs.  Instead we dlopen it with RTLD_NOLOAD here
+     to ensure it is initialised when present.  */
+  (void) dlopen ("libpthread.so", RTLD_LAZY | RTLD_GLOBAL | RTLD_NOLOAD);
+#else
+  /* For older versions this hack also triggers libpthread
+     initialisation.  */
+  (void) pthread_self ();
+#endif
+}
 #else
 /* Avoid AIX compiler warning.  */
 typedef int dummy;
