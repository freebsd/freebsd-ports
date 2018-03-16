--- gdb/arm-linux-tdep.c.orig	2018-03-15 10:36:38.853100000 +0100
+++ gdb/arm-linux-tdep.c	2018-03-15 10:42:37.222568000 +0100
@@ -385,7 +385,7 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { ARM_LINUX_SIGRETURN_INSTR, -1 },
+    { ARM_LINUX_SIGRETURN_INSTR, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_sigreturn_init
@@ -395,7 +395,7 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { ARM_LINUX_RT_SIGRETURN_INSTR, -1 },
+    { ARM_LINUX_RT_SIGRETURN_INSTR, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_rt_sigreturn_init
@@ -405,8 +405,8 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { ARM_SET_R7_SIGRETURN, -1 },
-    { ARM_EABI_SYSCALL, -1 },
+    { ARM_SET_R7_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { ARM_EABI_SYSCALL, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_sigreturn_init
@@ -416,8 +416,8 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { ARM_SET_R7_RT_SIGRETURN, -1 },
-    { ARM_EABI_SYSCALL, -1 },
+    { ARM_SET_R7_RT_SIGRETURN, static_cast<ULONGEST>(-1) },
+    { ARM_EABI_SYSCALL, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_rt_sigreturn_init
@@ -427,9 +427,9 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { THUMB2_SET_R7_SIGRETURN1, -1 },
-    { THUMB2_SET_R7_SIGRETURN2, -1 },
-    { THUMB2_EABI_SYSCALL, -1 },
+    { THUMB2_SET_R7_SIGRETURN1, static_cast<ULONGEST>(-1) },
+    { THUMB2_SET_R7_SIGRETURN2, static_cast<ULONGEST>(-1) },
+    { THUMB2_EABI_SYSCALL, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_sigreturn_init
@@ -439,9 +439,9 @@
   SIGTRAMP_FRAME,
   2,
   {
-    { THUMB2_SET_R7_RT_SIGRETURN1, -1 },
-    { THUMB2_SET_R7_RT_SIGRETURN2, -1 },
-    { THUMB2_EABI_SYSCALL, -1 },
+    { THUMB2_SET_R7_RT_SIGRETURN1, static_cast<ULONGEST>(-1) },
+    { THUMB2_SET_R7_RT_SIGRETURN2, static_cast<ULONGEST>(-1) },
+    { THUMB2_EABI_SYSCALL, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_rt_sigreturn_init
@@ -451,8 +451,8 @@
   NORMAL_FRAME,
   4,
   {
-    { ARM_OABI_SYSCALL_RESTART_SYSCALL, -1 },
-    { ARM_LDR_PC_SP_12, -1 },
+    { ARM_OABI_SYSCALL_RESTART_SYSCALL, static_cast<ULONGEST>(-1) },
+    { ARM_LDR_PC_SP_12, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_restart_syscall_init
@@ -462,8 +462,8 @@
   NORMAL_FRAME,
   4,
   {
-    { ARM_OABI_SYSCALL_RESTART_SYSCALL, -1 },
-    { ARM_LDR_PC_SP_4, -1 },
+    { ARM_OABI_SYSCALL_RESTART_SYSCALL, static_cast<ULONGEST>(-1) },
+    { ARM_LDR_PC_SP_4, static_cast<ULONGEST>(-1) },
     { TRAMP_SENTINEL_INSN }
   },
   arm_linux_restart_syscall_init
