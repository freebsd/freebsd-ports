--- liblog/logd_write.c.orig	2015-05-27 20:24:08 UTC
+++ liblog/logd_write.c
@@ -22,7 +22,9 @@
 #include <pthread.h>
 #endif
 #include <stdarg.h>
+#if (FAKE_LOG_DEVICE == 0)
 #include <stdatomic.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
