--- src/jsc/bindings/BunProcess.cpp.orig	2026-10-05 11:35:04.898918000 +0000
+++ src/jsc/bindings/BunProcess.cpp	2026-10-05 11:34:54.978133000 +0000
@@ -1634,8 +1634,14 @@
             // suspend and resume the JS thread which we must not override.
             if (signalNumber != SIGKILL && signalNumber != SIGSTOP && signalNumber != g_wtfConfig.sigThreadSuspendResume) {
 #elif OS(DARWIN) || OS(FREEBSD)
-            // these signals cannot be handled
+            // These signals cannot be handled. On FreeBSD JSC uses SIGUSR1 (not SIGPWR, as on
+            // Linux) for thread suspend/resume; overriding it makes Thread::suspend() hang when
+            // the VM shuts down. See wtf/posix/ThreadingPOSIX.cpp.
+#if OS(FREEBSD)
+            if (signalNumber != SIGKILL && signalNumber != SIGSTOP && signalNumber != g_wtfConfig.sigThreadSuspendResume) {
+#else
             if (signalNumber != SIGKILL && signalNumber != SIGSTOP) {
+#endif
 #elif OS(WINDOWS)
             // windows has no SIGSTOP
             if (signalNumber != SIGKILL) {
