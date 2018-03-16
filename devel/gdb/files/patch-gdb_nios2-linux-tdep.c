--- gdb/nios2-linux-tdep.c.orig	2018-03-15 11:23:52.815692000 +0100
+++ gdb/nios2-linux-tdep.c	2018-03-15 11:55:44.876122000 +0100
@@ -164,8 +164,8 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MATCH_R1_MOVI | SET_IW_I_B (2) | SET_IW_I_IMM16 (139), -1 },
-    { MATCH_R1_TRAP | SET_IW_R_IMM5 (0), -1},
+    { MATCH_R1_MOVI | SET_IW_I_B (2) | SET_IW_I_IMM16 (139), static_cast<ULONGEST>(-1) },
+    { MATCH_R1_TRAP | SET_IW_R_IMM5 (0), static_cast<ULONGEST>(-1)},
     { TRAMP_SENTINEL_INSN }
   },
   nios2_linux_rt_sigreturn_init
@@ -176,8 +176,8 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MATCH_R2_MOVI | SET_IW_F2I16_B (2) | SET_IW_F2I16_IMM16 (139), -1 },
-    { MATCH_R2_TRAP | SET_IW_X2L5_IMM5 (0), -1},
+    { MATCH_R2_MOVI | SET_IW_F2I16_B (2) | SET_IW_F2I16_IMM16 (139), static_cast<ULONGEST>(-1) },
+    { MATCH_R2_TRAP | SET_IW_X2L5_IMM5 (0), static_cast<ULONGEST>(-1)},
     { TRAMP_SENTINEL_INSN }
   },
   nios2_linux_rt_sigreturn_init
