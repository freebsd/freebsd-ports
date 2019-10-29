--- liblog/fake_writer.cpp.orig	2019-10-18 00:22:21 UTC
+++ liblog/fake_writer.cpp
@@ -34,7 +34,7 @@ static int logFds[(int)LOG_ID_MAX] = {-1, -1, -1, -1, 
 struct android_log_transport_write fakeLoggerWrite = {
     .name = "fake",
     .logMask = 0,
-    .context.priv = &logFds,
+    .context = { .priv = &logFds }, // GCC
     .available = fakeAvailable,
     .open = fakeOpen,
     .close = fakeClose,
