--- tests/i915/gem_mmap_gtt.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_mmap_gtt.c
@@ -54,6 +54,16 @@
 
 #define abs(x) ((x) >= 0 ? (x) : -(x))
 
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
 IGT_TEST_DESCRIPTION("Ensure that all operations around MMAP_GTT ioctl works.");
 
 static int OBJECT_SIZE = 16*1024*1024;
@@ -566,7 +576,11 @@ test_ptrace(int fd)
 	for (int i = 0; i < sz / sizeof(long); i++) {
 		long ret;
 
+#ifdef __linux__
 		ret = ptrace(PTRACE_PEEKDATA, pid, gtt + i);
+#elif defined(__FreeBSD__)
+		ret = ptrace(PTRACE_PEEKDATA, pid, gtt + i, 0);
+#endif
 		igt_assert_eq_u64(ret, CC);
 		cpy[i] = ret;
 
