--- src/daemon.c.orig	Mon Sep 23 11:15:29 2002
+++ src/daemon.c	Mon Sep 23 11:15:37 2002
@@ -170,7 +170,7 @@
 int dcc_refuse_root(void)
 {
     /* Just be careful */
-    if (getuid() == 0  ||  geteuid() == 0  ||  getgid() == 0 || getegid() == 0) {
+    if (getuid() == 0  ||  geteuid() == 0) {
         rs_log_crit("distccd must not be run as root!");
         return EXIT_DISTCC_FAILED;
     }
