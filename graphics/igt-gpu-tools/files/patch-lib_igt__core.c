--- lib/igt_core.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_core.c
@@ -43,7 +43,7 @@
 #include <unistd.h>
 #include <sys/wait.h>
 #include <sys/types.h>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/syscall.h>
 #endif
 #include <pthread.h>
@@ -85,6 +85,12 @@
 #include <libgen.h>   /* for basename() on Solaris */
 #endif
 
+#ifdef __FreeBSD__
+#define	gettid()				getpid()
+#define	pthread_sigqueue(pid, signo, value)	sigqueue(pid, signo, value)
+#define	sighandler_t				sig_t
+#endif
+
 /**
  * SECTION:igt_core
  * @short_description: Core i-g-t testing support
@@ -786,6 +792,7 @@ static void oom_adjust_for_doom(void)
 
 static void oom_adjust_for_doom(void)
 {
+#ifdef __linux__
 	int fd;
 	const char always_kill[] = "1000";
 
@@ -793,7 +800,7 @@ static void oom_adjust_for_doom(void)
 	igt_assert(fd != -1);
 	igt_assert(write(fd, always_kill, sizeof(always_kill)) == sizeof(always_kill));
 	close(fd);
-
+#endif
 }
 
 /**
@@ -2223,7 +2230,12 @@ bool __igt_fork_helper(struct igt_helper_process *proc
 		igt_assert(0);
 	case 0:
 		reset_helper_process_list();
+#ifdef __linux__
 		oom_adjust_for_doom();
+#elif defined(__FreeBSD__)
+		/* not a great substitution for oom_adjust_for_doom() */
+		raise(SIGTERM);
+#endif
 
 		return true;
 	default:
