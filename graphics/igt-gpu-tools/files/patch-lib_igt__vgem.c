--- lib/igt_vgem.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_vgem.c
@@ -30,6 +30,11 @@
 #include "igt_core.h"
 #include "ioctl_wrappers.h"
 
+#ifdef __FreeBSD__
+#define	mmap64(addr, len, prot, flags, fd, offset) \
+	mmap(addr, len, prot, flags, fd, offset)
+#endif
+
 /**
  * SECTION:igt_vgem
  * @short_description: VGEM support library
