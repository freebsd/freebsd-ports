--- liblog/fake_writer.cpp.orig	2019-07-17 19:54:09 UTC
+++ liblog/fake_writer.cpp
@@ -33,8 +33,8 @@ static int logFds[(int)LOG_ID_MAX] = {-1, -1, -1, -1, 
 
 struct android_log_transport_write fakeLoggerWrite = {
     .node = {&fakeLoggerWrite.node, &fakeLoggerWrite.node},
-    .context.priv = &logFds,
     .name = "fake",
+    .context = { .priv = &logFds }, // GCC
     .available = NULL,
     .open = fakeOpen,
     .close = fakeClose,
