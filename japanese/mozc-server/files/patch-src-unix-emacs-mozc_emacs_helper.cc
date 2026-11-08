--- src/unix/emacs/mozc_emacs_helper.cc.orig	2026-10-19 07:22:21 UTC
+++ src/unix/emacs/mozc_emacs_helper.cc
@@ -31,6 +31,9 @@
 #include <cstdio>
 #include <iostream>
 #include <memory>
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
 #include <string>
 #include <vector>
 
@@ -127,6 +130,15 @@ int main(int argc, char** argv) {
 
 int main(int argc, char** argv) {
   mozc::InitMozc(argv[0], &argc, &argv);
+
+#if defined(__FreeBSD__)
+  struct sigaction sa = {};
+  sa.sa_handler = SIG_DFL;
+  ::sigemptyset(&sa.sa_mask);
+  sa.sa_flags = SA_NOCLDWAIT;
+  CHECK_EQ(::sigaction(SIGCHLD, &sa, nullptr), 0);
+#endif
+
   if (absl::GetFlag(FLAGS_suppress_stderr)) {
 #ifdef _WIN32
     constexpr char kPath[] = "NUL";
