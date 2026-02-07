--- tests/vc4_purgeable_bo.c.orig	2022-08-31 20:00:01 UTC
+++ tests/vc4_purgeable_bo.c
@@ -35,6 +35,10 @@
 #include <sys/ioctl.h>
 #include "vc4_drm.h"
 
+#ifdef __FreeBSD__
+#undef	jmp_buf
+#endif
+
 struct igt_vc4_bo {
 	struct igt_list_head node;
 	int handle;
