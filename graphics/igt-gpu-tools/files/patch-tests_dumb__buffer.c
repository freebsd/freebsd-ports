--- tests/dumb_buffer.c.orig	2022-08-31 20:00:01 UTC
+++ tests/dumb_buffer.c
@@ -50,6 +50,11 @@
 #include "igt_aux.h"
 #include "ioctl_wrappers.h"
 
+#ifdef __FreeBSD__
+#undef	jmp_buf
+#define	sighandler_t	sig_t
+#endif
+
 IGT_TEST_DESCRIPTION("This is a test for the generic dumb buffer interface.");
 
 static int __dumb_create(int fd, struct drm_mode_create_dumb *create)
