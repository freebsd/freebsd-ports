--- liblog/stderr_write.cpp.orig	2019-08-13 02:10:58 UTC
+++ liblog/stderr_write.cpp
@@ -55,8 +55,8 @@ struct stderrContext {
 
 struct android_log_transport_write stderrLoggerWrite = {
     .node = {&stderrLoggerWrite.node, &stderrLoggerWrite.node},
-    .context.priv = NULL,
     .name = "stderr",
+    .context = { .priv = NULL }, // GCC
     .available = stderrAvailable,
     .open = stderrOpen,
     .close = stderrClose,
