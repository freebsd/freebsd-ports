--- gdb/i386-tdep.c	Mon Aug 26 11:35:25 2002
+++ gdb/i386-tdep.c	Sun Oct 13 14:15:58 2002
@@ -534,6 +534,9 @@
 static CORE_ADDR
 i386_frame_saved_pc (struct frame_info *frame)
 {
+  if (kernel_debugging)
+    return fbsd_kern_frame_saved_pc(frame);
+
   if (PC_IN_CALL_DUMMY (frame->pc, 0, 0))
     return generic_read_register_dummy (frame->pc, frame->frame,
 					PC_REGNUM);
