--- lib/igt_aux.h.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_aux.h
@@ -34,9 +34,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
-#ifdef __linux__
-# include <sys/syscall.h>
-#endif
+#include <sys/syscall.h>
 
 #include <i915/gem_submission.h>
 
@@ -48,8 +46,8 @@
 # ifndef HAVE_GETTID
 #  define gettid() (pid_t)(syscall(__NR_gettid))
 # endif
-#endif
 #define sigev_notify_thread_id _sigev_un._tid
+#endif
 
 /* auxialiary igt helpers from igt_aux.c */
 /* generally useful helpers */
