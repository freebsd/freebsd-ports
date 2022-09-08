--- lib/sw_sync.c.orig	2022-08-31 20:00:01 UTC
+++ lib/sw_sync.c
@@ -41,6 +41,10 @@
 #include "drmtest.h"
 #include "ioctl_wrappers.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 /**
  * SECTION:sw_sync
  * @short_description: Software sync (fencing) support library
