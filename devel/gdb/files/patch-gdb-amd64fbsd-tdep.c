--- gdb/amd64fbsd-tdep.c.orig	2010-01-01 02:31:29.000000000 -0500
+++ gdb/amd64fbsd-tdep.c	2011-01-05 17:27:29.264869000 -0500
@@ -40,12 +39,16 @@
 static CORE_ADDR
 amd64fbsd_sigcontext_addr (struct frame_info *this_frame)
 {
+  struct gdbarch *gdbarch = get_frame_arch (this_frame);
+  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
   CORE_ADDR sp;
+  gdb_byte buf[8];
 
   /* The `struct sigcontext' (which really is an `ucontext_t' on
      FreeBSD/amd64) lives at a fixed offset in the signal frame.  See
      <machine/sigframe.h>.  */
-  sp = frame_unwind_register_unsigned (this_frame, AMD64_RSP_REGNUM);
+  get_frame_register (this_frame, AMD64_RSP_REGNUM, buf);
+  sp = extract_unsigned_integer (buf, 8, byte_order);
   return sp + 16;
 }
 
