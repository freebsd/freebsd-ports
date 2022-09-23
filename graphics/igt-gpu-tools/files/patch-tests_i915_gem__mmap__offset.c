--- tests/i915/gem_mmap_offset.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_mmap_offset.c
@@ -38,6 +38,16 @@
 #include "igt.h"
 #include "igt_x86.h"
 
+#ifdef __FreeBSD__
+#define	mmap64(addr, len, prot, flags, fd, offset) \
+	mmap(addr, len, prot, flags, fd, offset)
+#define	PTRACE_TRACEME  PT_TRACE_ME
+#define	PTRACE_ATTACH   PT_ATTACH
+#define	PTRACE_PEEKDATA PT_READ_D
+#define	PTRACE_POKEDATA PT_WRITE_D
+#define	PTRACE_DETACH   PT_DETACH
+#endif
+
 IGT_TEST_DESCRIPTION("Basic MMAP_OFFSET IOCTL tests for mem regions\n");
 
 static int mmap_offset_ioctl(int i915, struct drm_i915_gem_mmap_offset *arg)
@@ -370,7 +380,11 @@ static void test_ptrace(int i915)
 			for (int i = 0; i < SZ / sizeof(long); i++) {
 				long ret;
 
+#ifdef __linux__
 				ret = ptrace(PTRACE_PEEKDATA, pid, ptr + i);
+#elif defined(__FreeBSD__)
+				ret = ptrace(PTRACE_PEEKDATA, pid, ptr + i, 0);
+#endif
 				igt_assert_eq_u64(ret, CC);
 				cpy[i] = ret;
 
