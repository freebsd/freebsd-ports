--- gdb/amd64fbsd-tdep.c.orig	2010-09-30 13:31:19.930008000 -0400
+++ gdb/amd64fbsd-tdep.c	2010-09-30 13:39:30.673331000 -0400
@@ -29,7 +29,6 @@
 #include "gdb_string.h"
 
 #include "amd64-tdep.h"
-#include "bsd-uthread.h"
 #include "solib-svr4.h"
 
 /* Support for signal handlers.  */
@@ -142,46 +141,6 @@
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
@@ -201,10 +160,6 @@
   tdep->sc_reg_offset = amd64fbsd_sc_reg_offset;
   tdep->sc_num_regs = ARRAY_SIZE (amd64fbsd_sc_reg_offset);
 
-  /* FreeBSD provides a user-level threads implementation.  */
-  bsd_uthread_set_supply_uthread (gdbarch, amd64fbsd_supply_uthread);
-  bsd_uthread_set_collect_uthread (gdbarch, amd64fbsd_collect_uthread);
-
   /* FreeBSD uses SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_lp64_fetch_link_map_offsets);
