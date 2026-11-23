--- node_modules/.pnpm/node-pty@1.2.0-beta.18/node_modules/node-pty/src/unix/pty.cc.orig	2026-11-22 04:33:50 UTC
+++ node_modules/.pnpm/node-pty@1.2.0-beta.18/node_modules/node-pty/src/unix/pty.cc
@@ -112,7 +112,7 @@ struct ExitEvent {
   int exit_code = 0, signal_code = 0;
 };
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 static int
 SetCloseOnExec(int fd) {
