--- lib/igt_syncobj.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_syncobj.c
@@ -27,6 +27,10 @@
 #include "igt.h"
 #include "igt_syncobj.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 /**
  * SECTION:igt_syncobj
  * @short_description: Library with syncobj helpers
