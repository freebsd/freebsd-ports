--- rtengine/jdatasrc.cc.orig	2024-02-16 05:12:09 UTC
+++ rtengine/jdatasrc.cc
@@ -409,6 +409,8 @@ my_jpeg_std_error (struct jpeg_error_mgr * err)
 GLOBAL(struct jpeg_error_mgr *)
 my_jpeg_std_error (struct jpeg_error_mgr * err)
 {
+    struct jpeg_error_mgr std_jpeg_err;
+    (void)jpeg_std_error(&std_jpeg_err);
 
     err->error_exit = my_error_exit;
     err->emit_message = emit_message;
@@ -421,7 +423,7 @@ my_jpeg_std_error (struct jpeg_error_mgr * err)
     err->msg_code = 0;        /* may be useful as a flag for "no error" */
 
     /* Initialize message table pointers */
-    err->jpeg_message_table = jpeg_std_message_table;
+    err->jpeg_message_table = std_jpeg_err.jpeg_message_table;
     err->last_jpeg_message = (int) JMSG_LASTMSGCODE - 1;
 
     err->addon_message_table = nullptr;
