--- liblog/stderr_write.cpp.orig	2019-07-17 19:54:09 UTC
+++ liblog/stderr_write.cpp
@@ -56,8 +56,8 @@ struct stderrContext {
 
 struct android_log_transport_write stderrLoggerWrite = {
     .node = {&stderrLoggerWrite.node, &stderrLoggerWrite.node},
-    .context.priv = NULL,
     .name = "stderr",
+    .context = { .priv = NULL }, // GCC
     .available = stderrAvailable,
     .open = stderrOpen,
     .close = stderrClose,
