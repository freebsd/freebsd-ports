--- gdb/i386fbsd-tdep.c.orig	2010-09-30 13:39:50.654492000 -0400
+++ gdb/i386fbsd-tdep.c	2010-09-30 13:40:43.858675000 -0400
@@ -28,7 +28,6 @@
 
 #include "i386-tdep.h"
 #include "i387-tdep.h"
-#include "bsd-uthread.h"
 #include "solib-svr4.h"
 
 /* FreeBSD 3.0-RELEASE or later.  */
@@ -84,46 +83,6 @@
 };
 
 static void
-i386fbsd_supply_uthread (struct regcache *regcache,
-			 int regnum, CORE_ADDR addr)
-{
-  gdb_byte buf[4];
-  int i;
-
-  gdb_assert (regnum >= -1);
-
-  for (i = 0; i < ARRAY_SIZE (i386fbsd_jmp_buf_reg_offset); i++)
-    {
-      if (i386fbsd_jmp_buf_reg_offset[i] != -1
-	  && (regnum == -1 || regnum == i))
-	{
-	  read_memory (addr + i386fbsd_jmp_buf_reg_offset[i], buf, 4);
-	  regcache_raw_supply (regcache, i, buf);
-	}
-    }
-}
-
-static void
-i386fbsd_collect_uthread (const struct regcache *regcache,
-			  int regnum, CORE_ADDR addr)
-{
-  gdb_byte buf[4];
-  int i;
-
-  gdb_assert (regnum >= -1);
-
-  for (i = 0; i < ARRAY_SIZE (i386fbsd_jmp_buf_reg_offset); i++)
-    {
-      if (i386fbsd_jmp_buf_reg_offset[i] != -1
-	  && (regnum == -1 || regnum == i))
-	{
-	  regcache_raw_collect (regcache, i, buf);
-	  write_memory (addr + i386fbsd_jmp_buf_reg_offset[i], buf, 4);
-	}
-    }
-}
-
-static void
 i386fbsdaout_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
@@ -148,10 +107,6 @@
   /* FreeBSD has a more complete `struct sigcontext'.  */
   tdep->sc_reg_offset = i386fbsd_sc_reg_offset;
   tdep->sc_num_regs = ARRAY_SIZE (i386fbsd_sc_reg_offset);
-
-  /* FreeBSD provides a user-level threads implementation.  */
-  bsd_uthread_set_supply_uthread (gdbarch, i386fbsd_supply_uthread);
-  bsd_uthread_set_collect_uthread (gdbarch, i386fbsd_collect_uthread);
 }
 
 static void
