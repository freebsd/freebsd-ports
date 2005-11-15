--- coregrind/vg_unistd.h.orig	Mon Nov  7 20:07:03 2005
+++ coregrind/vg_unistd.h	Mon Nov  7 20:07:28 2005
@@ -630,7 +630,7 @@
 #define	__NR_uuidgen	392
 #define	__NR_sendfile	393
 #define	__NR_mac_syscall	394
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
 #define	__NR_getfsstat	395
 #define	__NR_statfs	396
 #define	__NR_fstatfs	397
@@ -652,7 +652,7 @@
 #define	__NR_extattr_get_link	413
 #define	__NR_extattr_delete_link	414
 #define	__NR___mac_execve	415
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
 #define	__NR_sigaction	416
 #define	__NR_sigreturn	417
 #endif
@@ -665,7 +665,7 @@
 #define	__NR___acl_delete_link	427
 #define	__NR___acl_aclcheck_link	428
 #define	__NR_sigwait	429
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
 #define	__NR_thr_create	430
 #define	__NR_thr_exit	431
 #define	__NR_thr_self	432
