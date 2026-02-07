--- lib/igt_aux.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_aux.c
@@ -52,7 +52,9 @@
 #include <assert.h>
 #include <grp.h>
 
+#ifdef __linux__
 #include <proc/readproc.h>
+#endif
 #include <libudev.h>
 
 #include "drmtest.h"
@@ -75,6 +77,12 @@
 #include <libgen.h>   /* for dirname() */
 #endif
 
+#ifdef __FreeBSD__
+typedef struct { char state; } proc_t;
+#define	gettid()	getpid()
+#define	setpgrp()	setpgid(0, 0)
+#endif
+
 /**
  * SECTION:igt_aux
  * @short_description: Auxiliary libraries and support functions
@@ -1206,6 +1214,7 @@ void igt_unlock_mem(void)
 	locked_mem = NULL;
 }
 
+#ifdef __linux__
 /**
  * igt_is_process_running:
  * @comm: Name of process in the form found in /proc/pid/comm (limited to 15
@@ -1780,6 +1789,41 @@ igt_lsof_kill_audio_processes(void)
 
 	return fail;
 }
+#elif defined(__FreeBSD__)
+int
+igt_is_process_running(const char *comm)
+{
+	return -ENOSYS;
+}
+
+int
+igt_terminate_process(int sig, const char *comm)
+{
+	return -ENOSYS;
+}
+
+void
+igt_lsof(const char *dpath)
+{
+}
+
+int
+igt_lsof_kill_audio_processes(void)
+{
+	return -ENOSYS;
+}
+
+int
+pipewire_pulse_start_reserve(void)
+{
+	return -ENOSYS;
+}
+
+void
+pipewire_pulse_stop_reserve(void)
+{
+}
+#endif /* __linux__ */
 
 static struct igt_siglatency {
 	timer_t timer;
