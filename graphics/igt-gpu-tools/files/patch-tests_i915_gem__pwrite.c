--- tests/i915/gem_pwrite.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_pwrite.c
@@ -25,7 +25,9 @@
  *
  */
 
+#ifdef __linux__
 #include <linux/userfaultfd.h>
+#endif
 
 #include <pthread.h>
 #include <unistd.h>
@@ -283,7 +285,11 @@ static int userfaultfd(int flags)
 
 static int userfaultfd(int flags)
 {
+#ifdef __linux__
 	return syscall(SYS_userfaultfd, flags);
+#elif defined(__FreeBSD__)
+	return -ENOSYS;
+#endif
 }
 
 struct ufd_thread {
@@ -378,6 +384,7 @@ static void test_exhaustion(int i915)
 
 static void test_exhaustion(int i915)
 {
+#ifdef __linux__
 	struct uffdio_api api = { .api = UFFD_API };
 	struct uffdio_register reg;
 	struct uffdio_copy copy;
@@ -445,6 +452,7 @@ static void test_exhaustion(int i915)
 	close(ufd);
 
 	close(t.vgem);
+#endif
 }
 
 uint32_t *src, dst;
