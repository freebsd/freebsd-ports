--- gdb/sparc-tdep.c.orig	Sun Oct 20 18:21:09 2002
+++ gdb/sparc-tdep.c	Sun Oct 20 18:16:53 2002
@@ -450,6 +450,9 @@
   char *buf;
   CORE_ADDR addr;
 
+  if (kernel_debugging)
+    return fbsd_kern_frame_saved_pc(frame);
+
   buf = alloca (MAX_REGISTER_RAW_SIZE);
   if (frame->signal_handler_caller)
     {

