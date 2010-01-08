--- src/server/output.c.orig	2009-12-08 19:17:41.617402825 +0000
+++ src/server/output.c	2009-12-08 19:19:33.043039976 +0000
@@ -25,6 +25,13 @@
 
 #include "fdsetconv.c"
 #include "parse.h"
+#ifndef TEMP_FAILURE_RETRY
+#define TEMP_FAILURE_RETRY(expr) \
+  ({ long int _res; \
+     do _res = (long int) (expr); \
+     while (_res == -1L && errno == EINTR); \
+     _res; })
+#endif
 
 void
 output_set_speaking_monitor(TSpeechDMessage *msg, OutputModule *output)
