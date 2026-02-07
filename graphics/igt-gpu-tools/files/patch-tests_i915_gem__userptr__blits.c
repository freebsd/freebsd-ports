--- tests/i915/gem_userptr_blits.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_userptr_blits.c
@@ -36,7 +36,9 @@
  * The goal is to simply ensure the basics work.
  */
 
+#ifdef __linux__
 #include <linux/userfaultfd.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
@@ -66,6 +68,11 @@
 
 #include "eviction_common.c"
 
+#ifdef __FreeBSD__
+#define	ETIME		ETIMEDOUT
+#define	MADV_HUGEPAGE	MADV_SEQUENTIAL
+#endif
+
 #ifndef PAGE_SIZE
 #define PAGE_SIZE 4096
 #endif
@@ -2154,7 +2161,11 @@ static int userfaultfd(int flags)
 
 static int userfaultfd(int flags)
 {
+#ifdef __linux__
 	return syscall(SYS_userfaultfd, flags);
+#elif defined(__FreeBSD__)
+	return -ENOSYS;
+#endif
 }
 
 static bool has_userptr_probe(int fd)
@@ -2240,6 +2251,7 @@ static void test_userfault(int i915)
 
 static void test_userfault(int i915)
 {
+#ifdef __linux__
 	struct uffdio_api api = { .api = UFFD_API };
 	struct uffdio_register reg;
 	struct uffdio_copy copy;
@@ -2295,6 +2307,7 @@ static void test_userfault(int i915)
 
 	munmap(t.page, 4096);
 	close(ufd);
+#endif
 }
 
 uint64_t total_ram;
