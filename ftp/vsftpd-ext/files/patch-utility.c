--- utility.c.orig	2012-09-23 00:14:36 UTC
+++ utility.c
@@ -40,6 +40,10 @@ die2(const char* p_text1, const char* p_
 void
 bug(const char* p_text)
 {
+  static int inside_bug = 0;
+  if (inside_bug)
+    vsf_sysutil_exit(1);
+  inside_bug++;
   /* Rats. Try and write the reason to the network for diagnostics */
   vsf_sysutil_activate_noblock(VSFTP_COMMAND_FD);
   (void) vsf_sysutil_write_loop(VSFTP_COMMAND_FD, "500 OOPS: ", 10);
