--- tests/i915/gem_pread.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_pread.c
@@ -25,7 +25,9 @@
  *
  */
 
+#ifdef __linux__
 #include <linux/userfaultfd.h>
+#endif
 
 #include "igt.h"
 #include <unistd.h>
@@ -81,7 +83,11 @@ static int userfaultfd(int flags)
 
 static int userfaultfd(int flags)
 {
+#ifdef __linux__
 	return syscall(SYS_userfaultfd, flags);
+#elif defined(__FreeBSD__)
+	return -ENOSYS;
+#endif
 }
 
 struct ufd_thread {
@@ -154,6 +160,7 @@ static void test_exhaustion(int i915)
 
 static void test_exhaustion(int i915)
 {
+#ifdef __linux__
 	struct uffdio_api api = { .api = UFFD_API };
 	struct uffdio_register reg;
 	struct uffdio_copy copy;
@@ -221,6 +228,7 @@ static void test_exhaustion(int i915)
 	close(ufd);
 
 	close(t.vgem);
+#endif
 }
 
 #define OBJECT_SIZE 16384
