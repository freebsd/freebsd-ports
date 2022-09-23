--- tests/syncobj_timeline.c.orig	2022-08-31 20:00:01 UTC
+++ tests/syncobj_timeline.c
@@ -31,6 +31,10 @@
 #include <signal.h>
 #include "drm.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 IGT_TEST_DESCRIPTION("Tests for the drm timeline sync object API");
 
 /* One tenth of a second */
