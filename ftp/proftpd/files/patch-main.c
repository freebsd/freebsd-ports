--- src/main.c.orig	Wed Mar 15 19:41:01 2006
+++ src/main.c	Wed Nov 15 19:06:18 2006
@@ -116,6 +116,8 @@
 
 static char sbuf[PR_TUNABLE_BUFFER_SIZE] = {'\0'};
 
+#define PR_DEFAULT_CMD_BUFSZ	512
+
 static char **Argv = NULL;
 static char *LastArgv = NULL;
 static const char *PidPath = PR_PID_FILE_PATH;
@@ -820,16 +822,25 @@
       pr_timer_reset(TIMER_IDLE, NULL);
 
     if (cmd_buf_size == -1) {
-      long *buf_size = get_param_ptr(main_server->conf,
-        "CommandBufferSize", FALSE);
-
-      if (buf_size == NULL || *buf_size <= 0)
-        cmd_buf_size = 512;
+      int *bufsz = get_param_ptr(main_server->conf, "CommandBufferSize",
+        FALSE);
 
-      else if (*buf_size + 1 > sizeof(buf)) {
-	pr_log_pri(PR_LOG_WARNING, "Invalid CommandBufferSize size given. "
-          "Resetting to 512.");
-	cmd_buf_size = 512;
+      if (bufsz == NULL ||
+          *bufsz <= 0) {
+	pr_log_pri(PR_LOG_WARNING, "invalid CommandBufferSize size "
+          "given, resetting to default buffer size (%u)",
+          (unsigned int) PR_DEFAULT_CMD_BUFSZ);
+        cmd_buf_size = PR_DEFAULT_CMD_BUFSZ;
+
+      } else if (*bufsz + 1 > sizeof(buf)) {
+	pr_log_pri(PR_LOG_WARNING, "invalid CommandBufferSize size (%d) "
+          "given, resetting to default buffer size (%u)",
+          *bufsz, (unsigned int) PR_DEFAULT_CMD_BUFSZ);
+	cmd_buf_size = PR_DEFAULT_CMD_BUFSZ;
+
+      } else {
+        pr_log_debug(DEBUG1, "setting CommandBufferSize to %d", *bufsz);
+        cmd_buf_size = (long) *bufsz;
       }
     }
 
