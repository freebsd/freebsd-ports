--- tests/util/piglit-util.c.orig	2026-05-02 14:11:44 UTC
+++ tests/util/piglit-util.c
@@ -41,6 +41,9 @@
 #include <errno.h>
 #include <inttypes.h>
 #include <time.h>
+#ifdef __FreeBSD__
+#include <libgen.h>	/* For basename(3) */
+#endif
 
 #if defined(PIGLIT_HAS_POSIX_CLOCK_MONOTONIC) && defined(PIGLIT_HAS_POSIX_TIMER_NOTIFY_THREAD)
 #include <pthread.h>
