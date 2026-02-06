--- lib/bpf/src/skel_internal.h.orig	2025-10-27 20:52:10 UTC
+++ lib/bpf/src/skel_internal.h
@@ -74,7 +74,8 @@ static inline int skel_sys_bpf(enum bpf_cmd cmd, union
 #ifdef __KERNEL__
 	return kern_sys_bpf(cmd, attr, size);
 #else
-	return syscall(__NR_bpf, cmd, attr, size);
+	errno = ENOTSUP;
+	return -1;
 #endif
 }
 
