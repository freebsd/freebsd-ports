--- tests/drm_import_export.c.orig	2022-08-31 20:00:01 UTC
+++ tests/drm_import_export.c
@@ -45,6 +45,10 @@ IGT_TEST_DESCRIPTION("Basic check to verify the behavi
 #define DURATION 10
 IGT_TEST_DESCRIPTION("Basic check to verify the behaviour of libdrm bo for prime/flink");
 
+#ifdef __FreeBSD__
+#define	gettid()	getpid()
+#endif
+
 int fd;
 drm_intel_bufmgr *bufmgr;
 int fd1;
