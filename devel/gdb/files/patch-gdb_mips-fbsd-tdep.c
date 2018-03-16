--- gdb/mips-fbsd-tdep.c.orig	2018-03-15 11:11:08.892968000 +0100
+++ gdb/mips-fbsd-tdep.c	2018-03-15 11:14:38.323126000 +0100
@@ -342,11 +342,11 @@
   SIGTRAMP_FRAME,
   MIPS_INSN32_SIZE,
   {
-    { MIPS_INST_ADDIU_A0_SP_O32, -1 },	/* addiu   a0, sp, SIGF_UC */
-    { MIPS_INST_LI_V0_SIGRETURN, -1 },	/* li      v0, SYS_sigreturn */
-    { MIPS_INST_SYSCALL, -1 },		/* syscall */
-    { MIPS_INST_BREAK, -1 },		/* break */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_ADDIU_A0_SP_O32, static_cast<ULONGEST>(-1) },	/* addiu   a0, sp, SIGF_UC */
+    { MIPS_INST_LI_V0_SIGRETURN, static_cast<ULONGEST>(-1) },	/* li      v0, SYS_sigreturn */
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },		/* syscall */
+    { MIPS_INST_BREAK, static_cast<ULONGEST>(-1) },		/* break */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips_fbsd_sigframe_init
 };
@@ -434,11 +434,11 @@
   SIGTRAMP_FRAME,
   MIPS_INSN32_SIZE,
   {
-    { MIPS_INST_ADDIU_A0_SP_N32, -1 },	/* addiu   a0, sp, SIGF_UC */
-    { MIPS_INST_LI_V0_SIGRETURN, -1 },	/* li      v0, SYS_sigreturn */
-    { MIPS_INST_SYSCALL, -1 },		/* syscall */
-    { MIPS_INST_BREAK, -1 },		/* break */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_ADDIU_A0_SP_N32, static_cast<ULONGEST>(-1) },	/* addiu   a0, sp, SIGF_UC */
+    { MIPS_INST_LI_V0_SIGRETURN, static_cast<ULONGEST>(-1) },	/* li      v0, SYS_sigreturn */
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },		/* syscall */
+    { MIPS_INST_BREAK, static_cast<ULONGEST>(-1) },		/* break */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips64_fbsd_sigframe_init
 };
@@ -451,11 +451,11 @@
   SIGTRAMP_FRAME,
   MIPS_INSN32_SIZE,
   {
-    { MIPS_INST_DADDIU_A0_SP_N64, -1 },	/* daddiu  a0, sp, SIGF_UC */
-    { MIPS_INST_LI_V0_SIGRETURN, -1 },	/* li      v0, SYS_sigreturn */
-    { MIPS_INST_SYSCALL, -1 },		/* syscall */
-    { MIPS_INST_BREAK, -1 },		/* break */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { MIPS_INST_DADDIU_A0_SP_N64, static_cast<ULONGEST>(-1) },	/* daddiu  a0, sp, SIGF_UC */
+    { MIPS_INST_LI_V0_SIGRETURN, static_cast<ULONGEST>(-1) },	/* li      v0, SYS_sigreturn */
+    { MIPS_INST_SYSCALL, static_cast<ULONGEST>(-1) },		/* syscall */
+    { MIPS_INST_BREAK, static_cast<ULONGEST>(-1) },		/* break */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips64_fbsd_sigframe_init
 };
