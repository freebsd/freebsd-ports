--- tests/sw_sync.c.orig	2022-08-31 20:00:01 UTC
+++ tests/sw_sync.c
@@ -38,6 +38,9 @@
 
 #include "sw_sync.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
 
 IGT_TEST_DESCRIPTION("Test SW Sync Framework");
 
