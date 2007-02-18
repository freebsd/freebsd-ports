From: Steven Bosscher <stevenb.gcc@gmail.com>
To:  <gcc-patches@gcc.gnu.org>
Date: Sun, 18 Feb 2007 09:21:35 +0100
Message-Id: <200702180921.35650.steven@gcc.gnu.org>
Subject: [PATCH] Fix PR30773 and its duplicates

[...]

	* local-alloc.c (update_equiv_regs): Do not set reg_equiv_init
	if we fail to attach a REG_EQUIV note.

Index: gcc/local-alloc.c
===================================================================
--- local-alloc.c       (revision 121823)
+++ local-alloc.c       (working copy)
@@ -1062,10 +1062,11 @@ update_equiv_regs (void)
	{
	  rtx init_insn = XEXP (reg_equiv[regno].init_insns, 0);
	  if (validate_equiv_mem (init_insn, src, dest)
-	      && ! memref_used_between_p (dest, init_insn, insn))
+	      && ! memref_used_between_p (dest, init_insn, insn)
+	      /* Attaching a REG_EQUIV note will fail if INIT_INSN has
+		 multiple sets.  */
+	      && set_unique_reg_note (init_insn, REG_EQUIV, copy_rtx (dest)))
	    {
-	      set_unique_reg_note (init_insn, REG_EQUIV, copy_rtx (dest));
-
	      /* This insn makes the equivalence, not the one initializing
		 the register.  */
	      reg_equiv_init[regno]

