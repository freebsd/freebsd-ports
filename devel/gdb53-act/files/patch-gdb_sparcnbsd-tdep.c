diff -urN gdb/sparcnbsd-tdep.c.orig gdb/sparcnbsd-tdep.c
--- gdb/sparcnbsd-tdep.c.orig	Sat Oct 19 17:19:17 2002
+++ gdb/sparcnbsd-tdep.c	Sat Oct 19 17:44:47 2002
@@ -31,20 +31,6 @@
 
 #include "solib-svr4.h"
 
-#define REG32_OFFSET_PSR	(0 * 4)
-#define REG32_OFFSET_PC		(1 * 4)
-#define REG32_OFFSET_NPC	(2 * 4)
-#define REG32_OFFSET_Y		(3 * 4)
-#define REG32_OFFSET_GLOBAL	(4 * 4)
-#define REG32_OFFSET_OUT	(12 * 4)
-
-#define REG64_OFFSET_TSTATE	(0 * 8)
-#define REG64_OFFSET_PC		(1 * 8)
-#define REG64_OFFSET_NPC	(2 * 8)
-#define REG64_OFFSET_Y		(3 * 8)
-#define REG64_OFFSET_GLOBAL	(4 * 8)
-#define REG64_OFFSET_OUT	(12 * 8)
-
 void
 sparcnbsd_supply_reg32 (char *regs, int regno)
 {
@@ -375,16 +361,13 @@
 
   if (gdbarch_ptr_bit (current_gdbarch) == 32)
     {
-      reg_size = (20 * 4);
-      fpreg_size = (33 * 4);
+      reg_size = REG32_SIZE;
+      fpreg_size = FPREG32_SIZE;
     }
   else
     {
-      reg_size = (20 * 8);
-      fpreg_size = (64 * 4)
-        + 8  /* fsr */
-        + 4  /* gsr */
-        + 4; /* pad */
+      reg_size = REG64_SIZE;
+      fpreg_size = FPREG64_SIZE;
     }
 
   switch (which)
@@ -442,7 +425,7 @@
 
   jb_addr = read_register (O0_REGNUM);
 
-  if (target_read_memory (jb_addr + 12, buf, sizeof (buf)))
+  if (target_read_memory (jb_addr + JB32_OFFSET_PC, buf, sizeof (buf)))
     return 0;
 
   *pc = extract_address (buf, sizeof (buf));
@@ -458,7 +441,7 @@
 
   jb_addr = read_register (O0_REGNUM);
 
-  if (target_read_memory (jb_addr + 16, buf, sizeof (buf)))
+  if (target_read_memory (jb_addr + JB64_OFFSET_PC, buf, sizeof (buf)))
     return 0;
 
   *pc = extract_address (buf, sizeof (buf));
