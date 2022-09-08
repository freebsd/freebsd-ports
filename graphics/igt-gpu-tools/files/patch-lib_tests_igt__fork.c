--- lib/tests/igt_fork.c.orig	2022-08-31 20:00:01 UTC
+++ lib/tests/igt_fork.c
@@ -109,7 +109,11 @@ __noreturn static void subtest_leak(void)
 __noreturn static void subtest_leak(void)
 {
 	pid_t *children =
+#ifdef __linux__
 		mmap(0, 4096, PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
+#elif defined(__FreeBSD__)
+		mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
+#endif
 	const int num_children = 4096 / sizeof(*children);
 
 	igt_subtest_init(fake_argc, fake_argv);
