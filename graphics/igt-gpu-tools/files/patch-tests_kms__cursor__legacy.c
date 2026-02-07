--- tests/kms_cursor_legacy.c.orig	2022-08-31 20:00:01 UTC
+++ tests/kms_cursor_legacy.c
@@ -47,6 +47,10 @@
 
 #define PAGE_SIZE	4096
 
+#ifdef __FreeBSD__
+#define	SCHED_IDLE	SCHED_OTHER
+#endif
+
 IGT_TEST_DESCRIPTION("Stress legacy cursor ioctl");
 
 igt_pipe_crc_t *pipe_crc;
