--- lib/tests/igt_tests_common.h.orig	2022-08-31 20:00:01 UTC
+++ lib/tests/igt_tests_common.h
@@ -48,8 +48,17 @@ static inline void internal_assert_wsignaled(int wstat
 
 static inline void internal_assert_wsignaled(int wstatus, int signal)
 {
+#ifdef __linux__
 	internal_assert(WIFSIGNALED(wstatus) &&
 			WTERMSIG(wstatus) == signal);
+#elif defined(__FreeBSD__)
+	if (WIFSIGNALED(wstatus))
+		internal_assert(WTERMSIG(wstatus) == signal);
+	else if (WIFEXITED(wstatus))
+		internal_assert(WEXITSTATUS(wstatus) == signal + 128);
+	else
+		internal_assert(0);
+#endif
 }
 
 static inline void internal_assert_not_wsignaled(int wstatus)
