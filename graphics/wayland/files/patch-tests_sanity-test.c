--- tests/sanity-test.c.orig	2016-02-17 01:13:16 UTC
+++ tests/sanity-test.c
@@ -92,7 +92,8 @@ FAIL_TEST(sanity_malloc_direct)
 TEST(disable_leak_checks)
 {
 	volatile void *mem;
-	assert(leak_check_enabled);
+// XXX FreeBSD disables leak checks...
+//	assert(leak_check_enabled);
 	/* normally this should be on the beginning of the test.
 	 * Here we need to be sure, that the leak checks are
 	 * turned on */
@@ -171,7 +172,8 @@ sanity_fd_no_leak(void)
 {
 	int fd[2];
 
-	assert(leak_check_enabled);
+// XXX FreeBSD leak checks are disabled
+//	assert(leak_check_enabled);
 
 	/* leak 2 file descriptors */
 	if (pipe(fd) < 0)
