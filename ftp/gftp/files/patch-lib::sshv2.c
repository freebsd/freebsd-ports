--- lib/sshv2.c.orig	Wed Apr 23 22:45:50 2003
+++ lib/sshv2.c	Wed Apr 23 22:41:59 2003
@@ -523,7 +523,9 @@
   int version, fdm, fds, s[2];
   sshv2_message message;
   pid_t child;
-
+#ifdef __FreeBSD__
+  ssh_use_askpass=TRUE;
+#endif
   g_return_val_if_fail (request != NULL, -2);
   g_return_val_if_fail (request->protonum == GFTP_SSHV2_NUM, -2);
   g_return_val_if_fail (request->hostname != NULL, -2);
@@ -543,8 +545,13 @@
   if (request->sftpserv_path == NULL ||
       *request->sftpserv_path == '\0')
     {
+#ifdef __FreeBSD__
+      p1 = "/usr/libexec";
+      p2 = '/';
+#else
       p1 = "";
       p2 = ' ';
+#endif
     }
   else
     {
