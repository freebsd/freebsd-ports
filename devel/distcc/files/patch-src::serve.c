--- src/serve.c.orig	Tue Jun 25 15:42:07 2002
+++ src/serve.c	Tue Jun 25 15:42:30 2002
@@ -189,7 +189,7 @@
      *
      * XXX: Perhaps this should be optional so that we can compare
      * performance each way? */
-    if (mknod(temp_i, S_IFIFO|S_IRUSR|S_IWUSR, 0) == -1) {
+    if (mkfifo(temp_i, S_IFIFO|S_IRUSR|S_IWUSR) == -1) {
         rs_log_error("failed to make fifo %s: %s", temp_i,
                      strerror(errno));
         goto failed;
