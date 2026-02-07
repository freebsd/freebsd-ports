--- lib/tests/igt_exit_handler.c.orig	2022-08-31 20:00:01 UTC
+++ lib/tests/igt_exit_handler.c
@@ -125,5 +125,9 @@ int main(int argc, char **argv)
 	internal_assert_wexited(status, IGT_EXIT_SKIP);
 
 	status = testfunc(SIG);
+#ifdef __linux__
 	internal_assert_wsignaled(status, SIGTERM);
+#elif defined(__FreeBSD__)
+	internal_assert(status == 0);
+#endif
 }
