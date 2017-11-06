--- tests/test-runner.c.orig	2016-11-18 00:32:40 UTC
+++ tests/test-runner.c
@@ -25,6 +25,12 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -37,18 +43,35 @@
 #include <errno.h>
 #include <limits.h>
 #include <sys/ptrace.h>
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
 #ifndef PR_SET_PTRACER
 # define PR_SET_PTRACER 0x59616d61
 #endif
+#include <signal.h>
 
 #include "test-runner.h"
 
 static int num_alloc;
+
+extern const struct test __start_test_section, __stop_test_section;
+
+/* This is all disabled for FreeBSD because it gives "can't allocate initial
+ * thread" aborts otherwise. */
+#ifndef __FreeBSD__
 static void* (*sys_malloc)(size_t);
 static void (*sys_free)(void*);
 static void* (*sys_realloc)(void*, size_t);
 static void* (*sys_calloc)(size_t, size_t);
+#endif
+
+#ifdef __FreeBSD__
+/* XXX review ptrace() usage */
+#define PTRACE_ATTACH PT_ATTACH
+#define PTRACE_CONT PT_CONTINUE
+#define PTRACE_DETACH PT_DETACH
+#endif
 
 /* when set to 1, check if tests are not leaking memory and opened files.
  * It is turned on by default. It can be turned off by
@@ -57,7 +80,7 @@ int leak_check_enabled;
 
 /* when this var is set to 0, every call to test_set_timeout() is
  * suppressed - handy when debugging the test. Can be set by
- * WAYLAND_TEST_NO_TIMEOUTS environment variable. */
+ * WAYLAND_TESTS_NO_TIMEOUTS evnironment var */
 static int timeouts_enabled = 1;
 
 /* set to one if the output goes to the terminal */
@@ -65,6 +88,7 @@ static int is_atty = 0;
 
 extern const struct test __start_test_section, __stop_test_section;
 
+#ifndef __FreeBSD__
 __attribute__ ((visibility("default"))) void *
 malloc(size_t size)
 {
@@ -98,6 +122,7 @@ calloc(size_t nmemb, size_t size)
 
 	return sys_calloc(nmemb, size);
 }
+#endif
 
 static const struct test *
 find_test(const char *name)
@@ -292,6 +317,8 @@ is_debugger_attached(void)
 		return 0;
 	}
 
+
+// xxx start here
 	pid = fork();
 	if (pid == -1) {
 		perror("fork");
@@ -312,7 +339,7 @@ is_debugger_attached(void)
 			_exit(1);
 		if (!waitpid(-1, NULL, 0))
 			_exit(1);
-		ptrace(PTRACE_CONT, NULL, NULL);
+		ptrace(PTRACE_CONT, ppid, NULL, NULL);
 		ptrace(PTRACE_DETACH, ppid, NULL, NULL);
 		_exit(0);
 	} else {
@@ -346,17 +373,19 @@ int main(int argc, char *argv[])
 	const struct test *t;
 	pid_t pid;
 	int total, pass;
+#ifdef HAVE_WAITID
 	siginfo_t info;
+#else
+	int status;
+#endif
 
+#ifndef __FreeBSD__
 	/* Load system malloc, free, and realloc */
 	sys_calloc = dlsym(RTLD_NEXT, "calloc");
 	sys_realloc = dlsym(RTLD_NEXT, "realloc");
 	sys_malloc = dlsym(RTLD_NEXT, "malloc");
 	sys_free = dlsym(RTLD_NEXT, "free");
 
-	if (isatty(fileno(stderr)))
-		is_atty = 1;
-
 	if (is_debugger_attached()) {
 		leak_check_enabled = 0;
 		timeouts_enabled = 0;
@@ -364,6 +393,16 @@ int main(int argc, char *argv[])
 		leak_check_enabled = !getenv("WAYLAND_TEST_NO_LEAK_CHECK");
 		timeouts_enabled = !getenv("WAYLAND_TEST_NO_TIMEOUTS");
 	}
+#else
+	/* Disable leak checking on FreeBSD since we can't override malloc().  */
+	leak_check_enabled = 0;
+	/* XXX review later */
+	timeouts_enabled = 0;
+#endif
+
+	if (isatty(fileno(stderr)))
+		is_atty = 1;
+
 
 	if (argc == 2 && strcmp(argv[1], "--help") == 0)
 		usage(argv[0], EXIT_SUCCESS);
@@ -395,7 +434,8 @@ int main(int argc, char *argv[])
 		if (pid == 0)
 			run_test(t); /* never returns */
 
-		if (waitid(P_PID, pid, &info, WEXITED)) {
+#ifdef HAVE_WAITID
+		if (waitid(P_PID, 0, &info, WEXITED)) {
 			stderr_set_color(RED);
 			fprintf(stderr, "waitid failed: %m\n");
 			stderr_reset_color();
@@ -426,6 +466,25 @@ int main(int argc, char *argv[])
 
 			break;
 		}
+#else
+               if (waitpid(-1, &status, 0) == -1) {
+                       fprintf(stderr, "waitpid failed: %s\n",
+                               strerror(errno));
+                       abort();
+               }
+
+               fprintf(stderr, "test \"%s\":\t", t->name);
+               if (WIFEXITED(status)) {
+                       fprintf(stderr, "exit status %d", WEXITSTATUS(status));
+                       if (WEXITSTATUS(status) == EXIT_SUCCESS)
+                               success = 1;
+               } else if (WIFSIGNALED(status)) {
+                       fprintf(stderr, "signal %d", WTERMSIG(status));
+               }
+#endif
+
+		if (t->must_fail)
+			success = !success;
 
 		if (success) {
 			pass++;
