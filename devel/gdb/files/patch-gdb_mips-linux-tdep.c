--- gdb/mips-linux-tdep.c.orig	2018-03-15 11:07:40.749034000 +0100
+++ gdb/mips-linux-tdep.c	2018-03-15 11:09:52.878504000 +0100
@@ -831,9 +831,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MIPS_INST_LI_V0_SIGRETURN, -1 },
-    { MIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_LI_V0_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_o32_sigframe_init,
   mips_linux_sigframe_validate
@@ -843,9 +843,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MIPS_INST_LI_V0_RT_SIGRETURN, -1 },
-    { MIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 } },
+    { MIPS_INST_LI_V0_RT_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) } },
   mips_linux_o32_sigframe_init,
   mips_linux_sigframe_validate
 };
@@ -854,9 +854,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MIPS_INST_LI_V0_N32_RT_SIGRETURN, -1 },
-    { MIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_LI_V0_N32_RT_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_n32n64_sigframe_init,
   mips_linux_sigframe_validate
@@ -866,9 +866,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { MIPS_INST_LI_V0_N64_RT_SIGRETURN, -1 },
-    { MIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_LI_V0_N64_RT_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_n32n64_sigframe_init,
   mips_linux_sigframe_validate
@@ -878,11 +878,11 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { MICROMIPS_INST_LI_V0, -1 },
-    { MIPS_NR_sigreturn, -1 },
-    { MICROMIPS_INST_POOL32A, -1 },
-    { MICROMIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MICROMIPS_INST_LI_V0, static_cast<ULONGEST>(-1) },
+    { MIPS_NR_sigreturn, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_POOL32A, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_o32_sigframe_init,
   micromips_linux_sigframe_validate
@@ -892,11 +892,11 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { MICROMIPS_INST_LI_V0, -1 },
-    { MIPS_NR_rt_sigreturn, -1 },
-    { MICROMIPS_INST_POOL32A, -1 },
-    { MICROMIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MICROMIPS_INST_LI_V0, static_cast<ULONGEST>(-1) },
+    { MIPS_NR_rt_sigreturn, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_POOL32A, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_o32_sigframe_init,
   micromips_linux_sigframe_validate
@@ -906,11 +906,11 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { MICROMIPS_INST_LI_V0, -1 },
-    { MIPS_NR_N32_rt_sigreturn, -1 },
-    { MICROMIPS_INST_POOL32A, -1 },
-    { MICROMIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MICROMIPS_INST_LI_V0, static_cast<ULONGEST>(-1) },
+    { MIPS_NR_N32_rt_sigreturn, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_POOL32A, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_n32n64_sigframe_init,
   micromips_linux_sigframe_validate
@@ -920,11 +920,11 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { MICROMIPS_INST_LI_V0, -1 },
-    { MIPS_NR_N64_rt_sigreturn, -1 },
-    { MICROMIPS_INST_POOL32A, -1 },
-    { MICROMIPS_INST_SYSCALL, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MICROMIPS_INST_LI_V0, static_cast<ULONGEST>(-1) },
+    { MIPS_NR_N64_rt_sigreturn, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_POOL32A, static_cast<ULONGEST>(-1) },
+    { MICROMIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_linux_n32n64_sigframe_init,
   micromips_linux_sigframe_validate
