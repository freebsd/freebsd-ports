--- gdb/amd64fbsd-tdep.c.orig	2010-01-01 02:31:29.000000000 -0500
+++ gdb/amd64fbsd-tdep.c	2011-01-05 17:27:29.264869000 -0500
@@ -29,7 +29,6 @@
 #include "gdb_string.h"
 
 #include "amd64-tdep.h"
-#include "bsd-uthread.h"
 #include "solib-svr4.h"
 
 /* Support for signal handlers.  */
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
 
@@ -142,46 +145,6 @@
 };
 
 static void
-amd64fbsd_supply_uthread (struct regcache *regcache,
-			  int regnum, CORE_ADDR addr)
-{
-  gdb_byte buf[8];
-  int i;
-
-  gdb_assert (regnum >= -1);
-
-  for (i = 0; i < ARRAY_SIZE (amd64fbsd_jmp_buf_reg_offset); i++)
-    {
-      if (amd64fbsd_jmp_buf_reg_offset[i] != -1
-	  && (regnum == -1 || regnum == i))
-	{
-	  read_memory (addr + amd64fbsd_jmp_buf_reg_offset[i], buf, 8);
-	  regcache_raw_supply (regcache, i, buf);
-	}
-    }
-}
-
-static void
-amd64fbsd_collect_uthread (const struct regcache *regcache,
-			   int regnum, CORE_ADDR addr)
-{
-  gdb_byte buf[8];
-  int i;
-
-  gdb_assert (regnum >= -1);
-
-  for (i = 0; i < ARRAY_SIZE (amd64fbsd_jmp_buf_reg_offset); i++)
-    {
-      if (amd64fbsd_jmp_buf_reg_offset[i] != -1
-	  && (regnum == -1 || regnum == i))
-	{
-	  regcache_raw_collect (regcache, i, buf);
-	  write_memory (addr + amd64fbsd_jmp_buf_reg_offset[i], buf, 8);
-	}
-    }
-}
-
-static void
 amd64fbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
@@ -201,10 +164,6 @@
   tdep->sc_reg_offset = amd64fbsd_sc_reg_offset;
   tdep->sc_num_regs = ARRAY_SIZE (amd64fbsd_sc_reg_offset);
 
-  /* FreeBSD provides a user-level threads implementation.  */
-  bsd_uthread_set_supply_uthread (gdbarch, amd64fbsd_supply_uthread);
-  bsd_uthread_set_collect_uthread (gdbarch, amd64fbsd_collect_uthread);
-
   /* FreeBSD uses SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_lp64_fetch_link_map_offsets);
