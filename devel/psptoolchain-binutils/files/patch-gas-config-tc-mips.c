--- gas/config/tc-mips.c.orig	2005-06-12 19:07:03.000000000 +0100
+++ gas/config/tc-mips.c	2006-05-09 02:55:36.000000000 +0100
@@ -92,6 +92,32 @@
 
 #define ZERO 0
 #define AT  1
+#define V0  2
+#define V1  3
+#define A0  4
+#define A1  5
+#define A2  6
+#define A3  7
+#define T0  8
+#define T1  9
+#define T2  10
+#define T3  11
+#define T4  12
+#define T5  13
+#define T6  14
+#define T7  15
+#define S0  16
+#define S1  17
+#define S2  18
+#define S3  19
+#define S4  20
+#define S5  21
+#define S6  22
+#define S7  23
+#define T8  24
+#define T9  25
+#define K0  26
+#define K1  27
 #define TREG 24
 #define PIC_CALL_REG 25
 #define KT0 26
@@ -365,11 +391,15 @@
 #define CPU_HAS_MDMX(cpu)	(FALSE                 \
 				 )
 
+/* True if the given CPU belongs to the Allegrex family.  */
+#define CPU_IS_ALLEGREX(CPU)	((CPU) == CPU_ALLEGREX	\
+    				 )
+
 /* True if CPU has a dror instruction.  */
 #define CPU_HAS_DROR(CPU)	((CPU) == CPU_VR5400 || (CPU) == CPU_VR5500)
 
 /* True if CPU has a ror instruction.  */
-#define CPU_HAS_ROR(CPU)	CPU_HAS_DROR (CPU)
+#define CPU_HAS_ROR(CPU)	CPU_HAS_DROR (CPU) || CPU_IS_ALLEGREX (CPU)
 
 /* True if mflo and mfhi can be immediately followed by instructions
    which write to the HI and LO registers.
@@ -393,6 +423,7 @@
    || mips_opts.arch == CPU_R12000                    \
    || mips_opts.arch == CPU_RM7000                    \
    || mips_opts.arch == CPU_VR5500                    \
+   || mips_opts.arch == CPU_ALLEGREX                  \
    )
 
 /* Whether the processor uses hardware interlocks to protect reads
@@ -1142,6 +1173,8 @@
 static expressionS imm_expr;
 static expressionS imm2_expr;
 static expressionS offset_expr;
+static expressionS vimm_expr[4];
+static expressionS voffset_expr[4];
 
 /* Relocs associated with imm_expr and offset_expr.  */
 
@@ -1150,6 +1183,15 @@
 static bfd_reloc_code_real_type offset_reloc[3]
   = {BFD_RELOC_UNUSED, BFD_RELOC_UNUSED, BFD_RELOC_UNUSED};
 
+/* set by vfpu code for prefix instructions */
+
+static bfd_boolean vfpu_dprefix;
+static char vfpu_dprefix_str[64];
+static bfd_boolean vfpu_sprefix;
+static char vfpu_sprefix_str[64];
+static bfd_boolean vfpu_tprefix;
+static char vfpu_tprefix_str[64];
+
 /* These are set by mips16_ip if an explicit extension is used.  */
 
 static bfd_boolean mips16_small, mips16_ext;
@@ -1641,6 +1683,62 @@
       return;
     }
 
+  /* If we've generated operands for a VFPU prefix instruction then we need
+     to assemble and append the prefix instruction before emitting the
+     instruction it prefixes.  Note that in mips_ip prefix operands do not
+     cause any side effects with imm_expr or offset_expr.  If they did
+     we'd have to save and restore them here.  */
+  if (CPU_IS_ALLEGREX (mips_opts.arch) && ((vfpu_dprefix || vfpu_sprefix || vfpu_tprefix)))
+    {
+
+      if (mips_opts.noreorder
+	  && ( history[0].insn_mo->pinfo & (INSN_UNCOND_BRANCH_DELAY
+					   | INSN_COND_BRANCH_DELAY
+					   | INSN_COND_BRANCH_LIKELY)))
+	{
+	  as_bad (_("instruction with prefix cannot be used in branch delay slot"));
+	}
+
+      if (vfpu_dprefix)
+	{
+	  struct mips_cl_insn prefix;
+	  bfd_reloc_code_real_type unused_reloc[3]
+	    = {BFD_RELOC_UNUSED, BFD_RELOC_UNUSED, BFD_RELOC_UNUSED};
+	  char buf[256];
+
+	  sprintf (buf, "vpfxd %s", vfpu_dprefix_str);
+	  mips_ip (buf, &prefix);
+	  append_insn (&prefix, NULL, unused_reloc);
+	  vfpu_dprefix = FALSE;
+	}
+
+      if (vfpu_sprefix)
+	{
+	  struct mips_cl_insn prefix;
+	  bfd_reloc_code_real_type unused_reloc[3]
+	    = {BFD_RELOC_UNUSED, BFD_RELOC_UNUSED, BFD_RELOC_UNUSED};
+	  char buf[256];
+
+	  sprintf (buf, "vpfxs %s", vfpu_sprefix_str);
+	  mips_ip (buf, &prefix);
+	  append_insn ( &prefix, NULL, unused_reloc);
+	  vfpu_sprefix = FALSE;
+	}
+      
+      if (vfpu_tprefix)
+	{
+	  struct mips_cl_insn prefix;
+	  bfd_reloc_code_real_type unused_reloc[3]
+	    = {BFD_RELOC_UNUSED, BFD_RELOC_UNUSED, BFD_RELOC_UNUSED};
+	  char buf[256];
+
+	  sprintf (buf, "vpfxt %s", vfpu_tprefix_str);
+	  mips_ip (buf, &prefix);
+	  append_insn (&prefix, NULL, unused_reloc);
+	  vfpu_tprefix = FALSE;
+	}
+    }
+
   if (insn.insn_mo->pinfo == INSN_MACRO)
     {
       macro_start ();
@@ -3128,6 +3226,55 @@
 	  insn.insn_opcode |= va_arg (args, unsigned long);
 	  continue;
 
+	/* VFPU fields */
+	case '?':
+	  switch (*fmt++)
+	    {
+	    case 'o':
+	      *r = (bfd_reloc_code_real_type) va_arg (args, int);
+	      assert (*r == BFD_RELOC_GPREL16
+		      || *r == BFD_RELOC_MIPS_LITERAL
+		      || *r == BFD_RELOC_MIPS_HIGHER
+		      || *r == BFD_RELOC_HI16_S
+		      || *r == BFD_RELOC_LO16
+		      || *r == BFD_RELOC_MIPS_GOT16
+		      || *r == BFD_RELOC_MIPS_CALL16
+		      || *r == BFD_RELOC_MIPS_GOT_DISP
+		      || *r == BFD_RELOC_MIPS_GOT_PAGE
+		      || *r == BFD_RELOC_MIPS_GOT_OFST
+		      || *r == BFD_RELOC_MIPS_GOT_LO16
+		      || *r == BFD_RELOC_MIPS_CALL_LO16);
+	      break;
+	    case 'd':
+	      insn.insn_opcode |= va_arg (args, int) << VF_SH_VD;
+	      fmt += 2;
+	      break;
+	    case 's':
+	      insn.insn_opcode |= va_arg (args, int) << VF_SH_VS;
+	      fmt += 2;
+	      break;
+	    case 'm':
+	      {
+		int vtreg = va_arg (args, int);
+		insn.insn_opcode |= (vtreg & VF_MASK_VML) << VF_SH_VML;
+		insn.insn_opcode |= ((vtreg >> 5) & VF_MASK_VMH) << VF_SH_VMH;
+		fmt += 2;
+	      }
+	      break;
+	    case 'n':
+	      {
+		int vtreg = va_arg (args, int);
+		insn.insn_opcode |= (vtreg & VF_MASK_VNL) << VF_SH_VNL;
+		insn.insn_opcode |= ((vtreg >> 5) & VF_MASK_VNH) << VF_SH_VNH;
+		fmt += 2;
+	      }
+	      break;
+	    case 'e':
+	      insn.insn_opcode |= va_arg (args, int) << VF_SH_MCOND;
+	      break;
+	    }
+	  continue;
+
 	default:
 	  internalError ();
 	}
@@ -4103,6 +4250,7 @@
 macro (struct mips_cl_insn *ip)
 {
   register int treg, sreg, dreg, breg;
+  int vsreg, vtreg, vdreg, vmreg, vwb;
   int tempreg;
   int mask;
   int used_at = 0;
@@ -4128,6 +4276,13 @@
   sreg = breg = (ip->insn_opcode >> 21) & 0x1f;
   mask = ip->insn_mo->mask;
 
+  vmreg = ((ip->insn_opcode >> 16) & 0x1f)
+	| ((ip->insn_opcode <<  5) & 0x60);
+  vtreg = (ip->insn_opcode >> 16) & 0x7f;
+  vsreg = (ip->insn_opcode >> 8) & 0x7f;
+  vdreg = (ip->insn_opcode >> 0) & 0x7f;
+  vwb = (ip->insn_opcode >> 1) & 0x1;
+
   expr1.X_op = O_constant;
   expr1.X_op_symbol = NULL;
   expr1.X_add_symbol = NULL;
@@ -5654,6 +5809,26 @@
       /* Itbl support may require additional care here.  */
       coproc = 1;
       goto ld;
+    case M_LV_S_AB:
+      s = "lv.s";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto ld;
+    case M_LV_Q_AB:
+      s = "lv.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto ld;
+    case M_LVL_Q_AB:
+      s = "lvl.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto ld;
+    case M_LVR_Q_AB:
+      s = "lvr.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto ld;
     case M_LWL_AB:
       s = "lwl";
       lr = 1;
@@ -5738,6 +5913,29 @@
       /* Itbl support may require additional care here.  */
       coproc = 1;
       goto st;
+    case M_SV_S_AB:
+      s = "sv.s";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto st;
+    case M_SV_Q_AB:
+      if (vwb)
+	s = "vwb.q";
+      else
+	s = "sv.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto st;
+    case M_SVL_Q_AB:
+      s = "svl.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto st;
+    case M_SVR_Q_AB:
+      s = "svr.q";
+      /* Itbl support may require additional care here.  */
+      coproc = 1;
+      goto st;
     case M_SWL_AB:
       s = "swl";
       goto st;
@@ -5787,6 +5985,22 @@
 	  || mask == M_L_DAB
 	  || mask == M_S_DAB)
 	fmt = "T,o(b)";
+      else if (mask == M_LV_S_AB
+	       || mask == M_SV_S_AB)
+	{
+	  fmt = "?m0x,?o(b)";
+	  treg = vmreg;
+	}
+      else if (mask == M_LV_Q_AB
+	       || mask == M_SV_Q_AB
+	       || mask == M_LVL_Q_AB
+	       || mask == M_LVR_Q_AB
+	       || mask == M_SVL_Q_AB
+	       || mask == M_SVR_Q_AB)
+	{
+	  fmt = "?n3x,?o(b)";
+	  treg = vmreg;
+	}
       else if (coproc)
 	fmt = "E,o(b)";
       else
@@ -6150,6 +6364,138 @@
 	  break;
 	}
 
+    case M_LVI_S_SS:
+    case M_LVI_P_SS:
+    case M_LVI_T_SS:
+    case M_LVI_Q_SS:
+      {
+	int mtx = (vtreg >> VF_SH_MR_MTX) & VF_MASK_MR_MTX;
+	int idx = (vtreg >> VF_SH_MR_IDX) & VF_MASK_MR_IDX;
+	int fsl = 0;
+	int rxc = 0;
+	int vtreg_s = 0;
+	int vnum = 0;
+	int vat = 0;
+	int i;
+
+	switch (mask)
+	  {
+	  case M_LVI_S_SS:
+	    vnum = 1;
+	    fsl = (vtreg >> VF_SH_MR_FSL) & VF_MASK_MR_FSL;
+	    rxc = 0;
+	    break;
+	  case M_LVI_P_SS:
+	    vnum = 2;
+	    fsl = ((vtreg >> VF_SH_MR_VFSL) & VF_MASK_MR_VFSL) << 1;
+	    rxc = (vtreg >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+	    break;
+	  case M_LVI_T_SS:
+	    vnum = 3;
+	    fsl = (vtreg >> VF_SH_MR_VFSL) & VF_MASK_MR_VFSL;
+	    rxc = (vtreg >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+	    break;
+	  case M_LVI_Q_SS:
+	    vnum = 4;
+	    fsl = 0;
+	    rxc = (vtreg >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+	    break;
+	  }
+	if (rxc)
+	  vtreg_s = (mtx << VF_SH_MR_MTX) | (idx << VF_SH_MR_FSL)
+		  | (fsl << VF_SH_MR_IDX);
+	else
+	  vtreg_s = (mtx << VF_SH_MR_MTX) | (idx << VF_SH_MR_IDX)
+		  | (fsl << VF_SH_MR_FSL);
+
+	for (i = 0; i < vnum; i++) {
+	  imm_expr = vimm_expr[i];
+	  offset_expr = voffset_expr[i];
+
+	  if (imm_expr.X_op == O_constant)
+	    {
+	      load_register (AT, &imm_expr, 0);
+	      macro_build ((expressionS *) NULL,
+			   "mtv", "t,?d0z", AT, vtreg_s);
+	      vat = 1;
+	    }
+	  else
+	    {
+	      assert (offset_expr.X_op == O_symbol
+		      && strcmp (segment_name (S_GET_SEGMENT
+					       (offset_expr.X_add_symbol)),
+				 ".lit4") == 0
+		      && offset_expr.X_add_number == 0);
+	      macro_build (&offset_expr,
+			   "lv.s", "?m0x,?o(b)", vtreg_s,
+			   (int) BFD_RELOC_MIPS_LITERAL, mips_gp_register);
+	    }
+
+	  if (rxc)
+	    vtreg_s += (1 << VF_SH_MR_IDX);
+	  else
+	    vtreg_s += (1 << VF_SH_MR_FSL);
+	}
+
+	if (vat)
+	  break;
+	else
+	  return;
+      }
+
+    case M_LVHI_S_SS:
+    case M_LVHI_P_SS:
+      {
+	int mtx = (vtreg >> VF_SH_MR_MTX) & VF_MASK_MR_MTX;
+	int idx = (vtreg >> VF_SH_MR_IDX) & VF_MASK_MR_IDX;
+	int fsl = 0;
+	int rxc = 0;
+	int vtreg_s = 0;
+	int vnum = 0;
+	int i;
+	unsigned int f16v;
+	char f16v_str[16];
+
+	switch (mask)
+	  {
+	  case M_LVHI_S_SS:
+	    vnum = 2;
+	    fsl = (vtreg >> VF_SH_MR_FSL) & VF_MASK_MR_FSL;
+	    rxc = 0;
+	    break;
+	  case M_LVHI_P_SS:
+	    vnum = 4;
+	    fsl = ((vtreg >> VF_SH_MR_VFSL) & VF_MASK_MR_VFSL) << 1;
+	    rxc = (vtreg >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+	    break;
+	  }
+	if (rxc)
+	  vtreg_s = (mtx << VF_SH_MR_MTX) | (idx << VF_SH_MR_FSL)
+		  | (fsl << VF_SH_MR_IDX);
+	else
+	  vtreg_s = (mtx << VF_SH_MR_MTX) | (idx << VF_SH_MR_IDX)
+		  | (fsl << VF_SH_MR_FSL);
+
+
+	for (i = 0; i < vnum; i += 2) {
+	  f16v = ((vimm_expr[i + 1].X_add_number & 0xffff) << 16)
+	       | (vimm_expr[i].X_add_number & 0xffff);
+	  sprintf(f16v_str, "0x%08x", f16v);
+	  my_getExpression (&imm_expr, f16v_str);
+
+	  load_register (AT, &imm_expr, 0);
+	  macro_build ((expressionS *) NULL,
+		       "mtv", "t,?d0z", AT, vtreg_s);
+
+	  if (rxc)
+	    vtreg_s += (1 << VF_SH_MR_IDX);
+	  else
+	    vtreg_s += (1 << VF_SH_MR_FSL);
+	}
+
+	break;
+      }
+
     case M_LI_D:
       /* Check if we have a constant in IMM_EXPR.  If the GPRs are 64 bits
          wide, IMM_EXPR is the entire value.  Otherwise IMM_EXPR is the high
@@ -6672,6 +7018,27 @@
       move_register (dreg, sreg);
       break;
 
+    case M_VCMOV_S:
+      s = "vcmovt.s";
+      fmt = "?d0d,?s0s,?e";
+      goto vcmov;
+    case M_VCMOV_P:
+      s = "vcmovt.p";
+      fmt = "?d1d,?s1s,?e";
+      goto vcmov;
+    case M_VCMOV_T:
+      s = "vcmovt.t";
+      fmt = "?d2d,?s2s,?e";
+      goto vcmov;
+    case M_VCMOV_Q:
+      s = "vcmovt.q";
+      fmt = "?d3d,?s3s,?e";
+    vcmov:
+      macro_build ((expressionS *) NULL, s, fmt,
+		   vdreg, vsreg,
+		   (ip->insn_opcode >> VF_SH_MCOND) & VF_MASK_MCOND);
+      return;
+
 #ifdef LOSING_COMPILER
     default:
       /* Try and see if this is a new itbl instruction.
@@ -7348,6 +7715,39 @@
       move_register (treg, tempreg);
       break;
 
+    case M_ULV_S:
+      if (mips_opts.arch == CPU_ALLEGREX)
+	as_bad (_("opcode not supported on this processor"));
+      off = 3;
+      if (offset_expr.X_add_number >= 0x8000 - off)
+	as_bad (_("operand overflow"));
+      if (! target_big_endian)
+	offset_expr.X_add_number += off;
+      macro_build (&offset_expr, "lwl", "t,o(b)",
+		   AT, (int) BFD_RELOC_LO16, breg);
+      if (! target_big_endian)
+	offset_expr.X_add_number -= off;
+      else
+	offset_expr.X_add_number += off;
+      macro_build (&offset_expr, "lwr", "t,o(b)",
+		   AT, (int) BFD_RELOC_LO16, breg);
+
+      macro_build ((expressionS *) NULL, "mtv", "t,?d0z",
+		   AT, vmreg);
+      break;
+
+    case M_ULV_Q:
+      off = 12;
+      if (offset_expr.X_add_number >= 0x8000 - off)
+	as_bad (_("operand overflow"));
+      offset_expr.X_add_number += off;
+      macro_build (&offset_expr, "lvl.q", "?n3x,?o(b)",
+		   vmreg, (int) BFD_RELOC_LO16, breg);
+      offset_expr.X_add_number -= off;
+      macro_build (&offset_expr, "lvr.q", "?n3x,?o(b)",
+		   vmreg, (int) BFD_RELOC_LO16, breg);
+      return;
+
     case M_ULD_A:
       s = "ldl";
       s2 = "ldr";
@@ -7430,6 +7830,55 @@
       macro_build (&offset_expr, s2, "t,o(b)", treg, BFD_RELOC_LO16, breg);
       break;
 
+    case M_USV_S:
+      off = 3;
+      if (offset_expr.X_add_number >= 0x8000 - off)
+	as_bad (_("operand overflow"));
+      macro_build ((expressionS *) NULL, "mfv", "t,?d0z",
+		   AT, vmreg);
+      if (mips_opts.arch != CPU_ALLEGREX)
+	{
+	  if (! target_big_endian)
+	    offset_expr.X_add_number += off;
+	  macro_build (&offset_expr, "swl", "t,o(b)",
+		       AT, (int) BFD_RELOC_LO16, breg);
+	  if (! target_big_endian)
+	    offset_expr.X_add_number -= off;
+	  else
+	    offset_expr.X_add_number += off;
+	  macro_build (&offset_expr, "swr", "t,o(b)",
+		       AT, (int) BFD_RELOC_LO16, breg);
+	}
+      else
+	{
+	  if (target_big_endian)
+	    offset_expr.X_add_number += off;
+	  while (off-- >= 0)
+	    {
+	      macro_build (&offset_expr, "sb", "t,o(b)",
+			   AT, (int) BFD_RELOC_LO16, breg);
+	      macro_build ((expressionS *) NULL, "ror",
+			   "d,w,<", AT, AT, 8);
+	      if (target_big_endian)
+		--offset_expr.X_add_number;
+	      else
+		++offset_expr.X_add_number;
+	    }
+	}
+      break;
+
+    case M_USV_Q:
+      off = 12;
+      if (offset_expr.X_add_number >= 0x8000 - off)
+	as_bad (_("operand overflow"));
+      offset_expr.X_add_number += off;
+      macro_build (&offset_expr, "svl.q", "?n3x,?o(b)",
+		   vmreg, (int) BFD_RELOC_LO16, breg);
+      offset_expr.X_add_number -= off;
+      macro_build (&offset_expr, "svr.q", "?n3x,?o(b)",
+		   vmreg, (int) BFD_RELOC_LO16, breg);
+      return;
+
     case M_USD_A:
       s = "sdl";
       s2 = "sdr";
@@ -7817,6 +8266,103 @@
       case '%': USE_BITS (OP_MASK_VECALIGN,	OP_SH_VECALIGN); break;
       case '[': break;
       case ']': break;
+
+      /* VFPU fields */
+      case '?':
+	switch (c = *p++)
+	  {
+	  case '[': break;
+	  case ']': break;
+	  case 'y':
+	    {
+	      if ((*p != '0') && (*p != '1') && (*p != '2') && (*p != '3'))
+		{
+		  as_bad (_("internal: bad mips opcode : %s %s"),
+			  opc->name, opc->args);
+		  return 0;
+		}
+	      p++;
+	    }
+	    break;
+
+	  case 'o': USE_BITS (VF_MASK_OFFSET,   VF_SH_OFFSET);  break;
+
+	  case 's':
+	  case 't':
+	  case 'd':
+	  case 'v':
+	  case 'x':
+	  case 'm':
+	  case 'n':
+	    {
+	      if ((*p != '0') && (*p != '1') && (*p != '2') && (*p != '3')
+		  && (*p != '5') && (*p != '6') && (*p != '7'))
+		{
+		  as_bad (_("internal: bad mips opcode (vreg type `?%c'): %s %s"),
+			  *p, opc->name, opc->args);
+		  return 0;
+		}
+	      p++;
+
+	      if ((*p != 's') && (*p != 't') && (*p != 'd')
+		  && (*p != 'y') && (*p != 'x') && (*p != 'z')
+		  && (*p != 'w') && (*p != 'm'))
+		{
+		  as_bad (_("internal: bad mips opcode (vreg type `?%c'): %s %s"),
+			  *(p - 1), opc->name, opc->args);
+		}
+	      p++;
+
+	      switch (c)
+		{
+		case 's': USE_BITS (VF_MASK_VS,  VF_SH_VS);     break;
+		case 't': USE_BITS (VF_MASK_VT,  VF_SH_VT);     break;
+		case 'd':
+		case 'v':
+		case 'x': USE_BITS (VF_MASK_VD,  VF_SH_VD);     break;
+		case 'm': USE_BITS (VF_MASK_VML, VF_SH_VML);
+			  USE_BITS (VF_MASK_VMH, VF_SH_VMH);    break;
+		case 'n': USE_BITS (VF_MASK_VNL, VF_SH_VNL);
+			  USE_BITS (VF_MASK_VNH, VF_SH_VNH);    break;
+		}
+	    }
+	    break;
+
+	  case 'f': USE_BITS (VF_MASK_CC,       VF_SH_CC);
+		    p++;					break;
+
+	  case 'a': USE_BITS (VF_MASK_CONST,    VF_SH_CONST);   break;
+	  case 'b': USE_BITS (VF_MASK_SCALE,    VF_SH_SCALE);   break;
+	  case 'c': USE_BITS (VF_MASK_BCOND,    VF_SH_BCOND);   break;
+	  case 'e': USE_BITS (VF_MASK_MCOND,    VF_SH_MCOND);   break;
+
+	  case 'i': USE_BITS (VF_MASK_WRAP,     VF_SH_WRAP);    break;
+
+	  case 'q': USE_BITS (VF_MASK_VCD,      VF_SH_VCD);     break;
+	  case 'r': USE_BITS (VF_MASK_VCS,      VF_SH_VCS);     break;
+
+	  case 'u': USE_BITS (VF_MASK_HFLOAT,   VF_SH_HFLOAT);  break;
+
+	  case 'w': USE_BITS (VF_MASK_ROT,      VF_SH_ROT);     break;
+	  case 'z': USE_BITS (VF_MASK_RWB,      VF_SH_RWB);     break;
+
+	  case '0': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '1': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '2': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '3': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '4': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '5': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '6': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+	  case '7': USE_BITS (VF_MASK_PFX,      VF_SH_PFX);     break;
+
+	  default:
+	    as_bad (_("internal: bad mips opcode (unknown extension operand type `?%c'): %s %s"),
+		    c, opc->name, opc->args);
+	    return 0;
+
+	  }
+	break;
+
       default:
 	as_bad (_("internal: bad mips opcode (unknown operand type `%c'): %s %s"),
 		c, opc->name, opc->args);
@@ -7845,12 +8391,15 @@
   char c = 0;
   struct mips_opcode *insn;
   char *argsStart;
-  unsigned int regno;
+  unsigned int regno = 0;
   unsigned int lastregno = 0;
   unsigned int lastpos = 0;
   unsigned int limlo, limhi;
   char *s_reset;
   char save_c = 0;
+  unsigned int vdregno = 0xffff;
+  char vdregt = 0;
+  char vdregl = 0;
 
   insn_error = NULL;
 
@@ -8238,26 +8787,1171 @@
 	      s = expr_end;
 	      continue;
 
-	    case 'b':		/* base register */
-	    case 'd':		/* destination register */
-	    case 's':		/* source register */
-	    case 't':		/* target register */
-	    case 'r':		/* both target and source */
-	    case 'v':		/* both dest and source */
-	    case 'w':		/* both dest and target */
-	    case 'E':		/* coprocessor target register */
-	    case 'G':		/* coprocessor destination register */
-	    case 'K':		/* 'rdhwr' destination register */
-	    case 'x':		/* ignore register name */
-	    case 'z':		/* must be zero register */
-	    case 'U':           /* destination register (clo/clz).  */
-	      s_reset = s;
-	      if (s[0] == '$')
+	    /* VFPU fields */
+	    case '?':
+	    switch (*++args)
 		{
+	      case '[':
+	      case ']':
+		if (*s++ == *args)
+		  continue;
+		break;
 
-		  if (ISDIGIT (s[1]))
-		    {
-		      ++s;
+	      case 'y':		/* immediate separator */
+		++args;
+		vimm_expr[*args - '0'] = imm_expr;
+		voffset_expr[*args - '0'] = offset_expr;
+
+		imm_expr.X_op = O_absent;
+		offset_expr.X_op = O_absent;
+		imm_reloc[0] = BFD_RELOC_UNUSED;
+		imm_reloc[1] = BFD_RELOC_UNUSED;
+		imm_reloc[2] = BFD_RELOC_UNUSED;
+		offset_reloc[0] = BFD_RELOC_UNUSED;
+		offset_reloc[1] = BFD_RELOC_UNUSED;
+		offset_reloc[2] = BFD_RELOC_UNUSED;
+
+		continue;
+
+	      case 'o':		/* 16 bit offset */
+		/* Check whether there is only a single bracketed expression
+		   left.  If so, it must be the base register and the
+		   constant must be zero.  */
+		if (*s == '(' && strchr (s + 1, '(') == 0)
+		  {
+		    offset_expr.X_op = O_constant;
+		    offset_expr.X_add_number = 0;
+		    continue;
+		  }
+
+		/* If this value won't fit into a 16 bit offset, then go
+		   find a macro that will generate the 32 bit offset
+		   code pattern.  */
+		if (my_getSmallExpression (&offset_expr, offset_reloc, s) == 0
+		    && (offset_expr.X_op != O_constant
+			|| offset_expr.X_add_number >= 0x8000
+			|| offset_expr.X_add_number < -0x8000))
+		  break;
+
+		s = expr_end;
+		continue;
+
+	      case 's':		/* VFPU source register */
+	      case 't':		/* VFPU target register */
+	      case 'd':		/* VFPU destination register */
+	      case 'v':		/* VFPU destination register */
+	      case 'x':		/* VFPU destination register */
+	      case 'm':		/* VFPU target regsiter (load/store) */
+	      case 'n':		/* VFPU target regsiter (load/store) */
+		{
+		  int dtype_err = 0;
+		  int dnum_err = 0;
+		  int dlen = 0;
+		  char dtype = s[0];
+		  char regtype = *(args + 1);
+
+		  int mtx = 0;
+		  int idx = 0;
+		  int rxc = 0;
+		  int fsl = 0;
+		  int vidx = 0;
+		  int vfsl = 0;
+
+		  if (ISDIGIT (s[1]))
+		    {
+		      int num = 0;
+		      s++;
+		      do
+			{
+			  num *= 10;
+			  num += *s - '0';
+			  dlen++;
+			  s++;
+			}
+		      while (ISDIGIT (*s));
+
+		      if ((s[0] == '.')
+			  && (s[1] == 's' || s[1] == 'p'
+			      || s[1] == 't' || s[1] == 'q'))
+			s += 2;
+
+		      if (ISUPPER(dtype))
+			dtype -= 'A' - 'a';
+
+		      if (dtype == '$')
+			{
+			  regno = num;
+			  if (regno > VF_MAX_MR)
+			    as_bad (_("Invalid VFPU register number (%d)"),
+				    regno);
+
+			  idx = (num >> VF_SH_MR_IDX) & VF_MASK_MR_IDX;
+			  vfsl = (num >> VF_SH_MR_VFSL) & VF_MASK_MR_VFSL;
+			  switch (regtype)
+			    {
+			    case '0':	/* single word */
+			      break;
+			    case '1':	/* pare word */
+			      dnum_err = (vfsl & 0x1);
+			      break;
+			    case '2':	/* triple word */
+			      dnum_err = (vfsl > 1);
+			      break;
+			    case '3':	/* quad word */
+			      dnum_err = (vfsl > 0);
+			      break;
+			    case '5':	/* 2x2 word */
+			      dnum_err = (vfsl & 0x1) || (idx & 0x1);
+			      break;
+			    case '6':	/* 3x3 word */
+			      dnum_err = (vfsl > 1) || (idx > 1);
+			      break;
+			    case '7':	/* 4x4 word */
+			      dnum_err = (vfsl > 0) || (idx > 0);
+			      break;
+			    }
+
+			  if (dnum_err)
+			    as_bad (_("Improper VFPU register number (%d)"),
+				     regno);
+
+			}
+		      else if ((dlen == 3)
+			       && ((dtype == 's')
+				   || (dtype == 'c') || (dtype == 'r')
+				   || (dtype == 'm') || (dtype == 'e')))
+			{
+			  mtx = num / 100;
+			  if ((dtype == 'r') || (dtype == 'e'))
+			    {
+			      vfsl = (num / 10) % 10;
+			      vidx = num % 10;
+			      rxc = 1;
+			    }
+			  else
+			    {
+			      vidx = (num / 10) % 10;
+			      vfsl = num % 10;
+			      rxc = 0;
+			    }
+
+			  switch (regtype)
+			    {
+			    case '0':	/* single word */
+			      idx = vidx;
+			      fsl = vfsl;
+			      dtype_err = (dtype != 's');
+			      break;
+			    case '1':	/* pare word */
+			      idx = vidx;
+			      fsl = (vfsl & 0x2) | rxc;
+			      dnum_err = (vfsl & 0x1);
+			      dtype_err = (dtype != 'c') && (dtype != 'r');
+			      break;
+			    case '2':	/* triple word */
+			      idx = vidx;
+			      fsl = ((vfsl & 0x1) << 1) | rxc;
+			      dnum_err = (vfsl > 1);
+			      dtype_err = (dtype != 'c') && (dtype != 'r');
+			      break;
+			    case '3':	/* quad word */
+			      idx = vidx;
+			      fsl = rxc;
+			      dnum_err = (vfsl > 0);
+			      dtype_err = (dtype != 'c') && (dtype != 'r');
+			      break;
+			    case '5':	/* 2x2 word */
+			      idx = vidx & 0x2;
+			      fsl = (vfsl & 0x2) | rxc;
+			      dnum_err = (vfsl & 0x1) || (vidx & 0x1);
+			      dtype_err = (dtype != 'm') && (dtype != 'e');
+			      break;
+			    case '6':	/* 3x3 word */
+			      idx = vidx & 0x1;
+			      fsl = ((vfsl & 0x1) << 1) | rxc;
+			      dnum_err = (vfsl > 1) || (vidx > 1);
+			      dtype_err = (dtype != 'm') && (dtype != 'e');
+			      break;
+			    case '7':	/* 4x4 word */
+			      idx = 0;
+			      fsl = rxc;
+			      dnum_err = (vfsl > 0) || (vidx > 0);
+			      dtype_err = (dtype != 'm') && (dtype != 'e');
+			      break;
+			    }
+
+			  if (dtype_err)
+			    as_bad (_("Improper VFPU register prefix '%c'"),
+				     dtype);
+			  if (dnum_err)
+			    as_bad (_("Improper VFPU register number (%03d)"),
+				     num);
+
+			  if (mtx > VF_MAX_MR_MTX)
+			    as_bad (_("VFPU matrix range over %d"), mtx);
+			  if (vidx > VF_MAX_MR_IDX)
+			    as_bad (_("VFPU index range over %d"), idx);
+			  if (vfsl > VF_MAX_MR_FSL)
+			    as_bad (_("VFPU field select range over %d"), fsl);
+	      
+			  regno = ((fsl & VF_MASK_MR_FSL) << VF_SH_MR_FSL)
+				| ((mtx & VF_MASK_MR_MTX) << VF_SH_MR_MTX)
+				| ((idx & VF_MASK_MR_IDX) << VF_SH_MR_IDX);
+			}
+		      else
+			{
+			    as_bad (_("Improper VFPU register prefix '%c'"),
+				     dtype);
+			}
+		    }
+		  else
+		    {
+		      as_bad (_("bad operand %s"), s);
+		    }
+
+		  if ((*args == 'v') || (*args == 'x'))
+		    {
+		      vdregno = regno;
+		      vdregt = regtype;
+		      vdregl = (*args == 'v');
+		    }
+		  else if (vdregno <= VF_MAX_MR)
+		    {
+		      static unsigned short used_vreg[8][16] = {
+			{ 0x0001, 0x0010, 0x0100, 0x1000,
+			  0x0002, 0x0020, 0x0200, 0x2000,
+			  0x0004, 0x0040, 0x0400, 0x4000,
+			  0x0008, 0x0080, 0x0800, 0x8000 },
+			{ 0x0003, 0x0030, 0x0300, 0x3000,
+			  0x0011, 0x0022, 0x0044, 0x0088,
+			  0x000c, 0x00c0, 0x0c00, 0xc000,
+			  0x1100, 0x2200, 0x4400, 0x8800 },
+			{ 0x0007, 0x0070, 0x0700, 0x7000,
+			  0x0111, 0x0222, 0x0444, 0x0888,
+			  0x000e, 0x00e0, 0x0e00, 0xe000,
+			  0x1110, 0x2220, 0x4440, 0x8880 },
+			{ 0x000f, 0x00f0, 0x0f00, 0xf000,
+			  0x1111, 0x2222, 0x4444, 0x8888,
+			  0x000f, 0x00f0, 0x0f00, 0xf000,
+			  0x1111, 0x2222, 0x4444, 0x8888 },
+			{ 0x0000, 0x0000, 0x0000, 0x0000,
+			  0x0000, 0x0000, 0x0000, 0x0000,
+			  0x0000, 0x0000, 0x0000, 0x0000,
+			  0x0000, 0x0000, 0x0000, 0x0000 },
+			{ 0x0033, 0x0033, 0x3300, 0x3300,
+			  0x0033, 0x0033, 0x00cc, 0x00cc,
+			  0x00cc, 0x00cc, 0xcc00, 0xcc00,
+			  0x3300, 0x3300, 0xcc00, 0xcc00 },
+			{ 0x0777, 0x7770, 0x0777, 0x7770,
+			  0x0777, 0x0eee, 0x0777, 0x0eee,
+			  0x0eee, 0xeee0, 0x0eee, 0xeee0,
+			  0x7770, 0xeee0, 0x7770, 0xeee0 },
+			{ 0xffff, 0xffff, 0xffff, 0xffff,
+			  0xffff, 0xffff, 0xffff, 0xffff,
+     			  0xffff, 0xffff, 0xffff, 0xffff,
+			  0xffff, 0xffff, 0xffff, 0xffff },
+		      };
+		      int dmtx, smtx;
+		      int dfsl, sfsl;
+		      int didx, sidx;
+		      int drxc, srxc;
+
+		      dmtx = (vdregno >> VF_SH_MR_MTX) & VF_MASK_MR_MTX;
+		      smtx = (regno   >> VF_SH_MR_MTX) & VF_MASK_MR_MTX;
+
+		      if (dmtx == smtx)
+			{
+			  unsigned short dused, sused;
+			  int dtype, stype;
+
+			  dfsl = (vdregno >> VF_SH_MR_FSL) & VF_MASK_MR_FSL;
+			  didx = (vdregno >> VF_SH_MR_IDX) & VF_MASK_MR_IDX;
+			  drxc = (vdregno >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+			  sfsl = (regno   >> VF_SH_MR_FSL) & VF_MASK_MR_FSL;
+			  sidx = (regno   >> VF_SH_MR_IDX) & VF_MASK_MR_IDX;
+			  srxc = (regno   >> VF_SH_MR_RXC) & VF_MASK_MR_RXC;
+
+			  dtype = vdregt - '0';
+			  stype = regtype - '0';
+			  dused = used_vreg[dtype][(dfsl << 2) + didx];
+			  sused = used_vreg[stype][(sfsl << 2) + sidx];
+
+			  if ((dused & sused)
+			      && (vdregl || (dused ^ sused) || (drxc != srxc)))
+			    {
+			      int dvfsl;
+			      dvfsl = (vdregno >> VF_SH_MR_VFSL) & VF_MASK_MR_VFSL;
+			      switch (vdregt)
+				{
+				case '1':
+				  dvfsl <<= 1;
+				case '2':
+				case '3':
+				  if (drxc)
+				    as_bad (_("VFPU register conflict(R%d%d%d)"),
+					     dmtx, dvfsl, didx);
+				  else
+				    as_bad (_("VFPU register conflict(C%d%d%d)"),
+					     dmtx, didx, dvfsl);
+				  break;
+				case '5':
+				  dvfsl <<= 1;
+				case '6':
+				case '7':
+				  if (drxc)
+				    as_bad (_("VFPU register conflict(E%d%d%d)"),
+					     dmtx, dvfsl, didx);
+				  else
+				    as_bad (_("VFPU register conflict(M%d%d%d)"),
+					     dmtx, didx, dvfsl);
+				  break;
+				}
+			    }
+			}
+		    }
+
+		  switch (*args++)
+		    {
+		    case 's':
+		      if (
+			  (ip->insn_opcode
+			      & VFPU_MASK_RPT_MMUL) == VFPU_INST_RPT_MMUL)
+			{
+			  if (regno & (VF_MASK_MR_RXC << VF_SH_MR_RXC))
+			    regno &= ~(VF_MASK_MR_RXC << VF_SH_MR_RXC);
+			  else
+			    regno |= (VF_MASK_MR_RXC << VF_SH_MR_RXC);
+			}
+		      ip->insn_opcode |= (regno & VF_MASK_VS) << VF_SH_VS;
+		      break;
+		    case 't':
+		      ip->insn_opcode |= (regno & VF_MASK_VT) << VF_SH_VT;
+		      break;
+		    case 'd':
+		    case 'v':
+		    case 'x':
+		      ip->insn_opcode |= (regno & VF_MASK_VD) << VF_SH_VD;
+		      break;
+		    case 'm':
+		      {
+			int vmregL = (regno >> 0) & VF_MASK_VML;
+			int vmregH = (regno >> 5) & VF_MASK_VMH;
+			ip->insn_opcode |= (vmregL << VF_SH_VML)
+					| (vmregH << VF_SH_VMH);
+		      }
+		      break;
+		    case 'n':
+		      {
+			int vmregL = (regno >> 0) & VF_MASK_VNL;
+			int vmregH = (regno >> 5) & VF_MASK_VNH;
+			ip->insn_opcode |= (vmregL << VF_SH_VNL)
+					| (vmregH << VF_SH_VNH);
+		      }
+		      break;
+		    }
+		  args++;
+
+		  /* now check for vfpu prefixes if necessary */
+		  if (*s == '[')
+		    {
+		      char *prefix_out = NULL;
+		      bfd_boolean *prefix_bool = NULL;
+		      char *prefix_type = NULL;
+		      int num_args = 0;
+		      char *ob = ++s;
+		      bfd_boolean has_w = FALSE;
+		      bfd_boolean has_z = FALSE;
+		      bfd_boolean has_y = FALSE;
+		      bfd_boolean has_operator = FALSE;
+		      bfd_boolean has_saturater = FALSE;
+
+		      switch (*args)
+			{
+			case 'w':	/* only swizzle */
+			case 's':	/* source prefix */
+			  prefix_bool = &vfpu_sprefix;
+			  prefix_out = vfpu_sprefix_str;
+			  prefix_type = "source";
+			  break;
+			case 't':	/* target prefix */
+			  prefix_bool = &vfpu_tprefix;
+			  prefix_out = vfpu_tprefix_str;
+			  prefix_type = "target";
+			  break;
+			case 'm':	/* only write mask */
+			case 'd':	/* destination prefix */
+			  prefix_bool = &vfpu_dprefix;
+			  prefix_out = vfpu_dprefix_str;
+			  prefix_type = "destination";
+			  break;
+			case 'y':	/* inhibit */
+			  prefix_bool = NULL;
+			  prefix_type = "source";
+			  break;
+			case 'x':	/* inhibit */
+			  prefix_bool = NULL;
+			  prefix_type = "target";
+			  break;
+			case 'z':	/* inhibit */
+			  prefix_bool = NULL;
+			  prefix_type = "destination";
+			  break;
+			}
+
+		      for ( ; *s != '\0' && *s != ']'; s++)
+			{
+			  switch (*s)
+			    {
+			    case ',':
+			      /* count no. of params for syntax check */
+			      num_args++;
+			      break;
+			    case ' ':
+			    case '\t':
+			      break;
+			    case 'm':
+			    case 'M':
+			    case 'x':
+			    case 'X':
+			      break;
+			    case 'y':
+			    case 'Y':
+			      has_y = TRUE;
+			      break;
+			    case 'z':
+			    case 'Z':
+			      has_z = TRUE;
+			      break;
+			    case 'w':
+			    case 'W':
+			      has_w = TRUE;
+			      break;
+			    default:
+			      if (*args == 'w')
+				has_operator = TRUE;
+			      if (*args == 'm')
+				has_saturater = TRUE;
+			    }
+			}
+
+		      if (*s == ']')
+			{
+			  if (prefix_bool)
+			    {
+			      *prefix_bool = TRUE;
+			      strncpy (prefix_out, ob, s - ob);
+			      prefix_out[s - ob] = '\0';
+			      s++;
+			    }
+			  else
+			    {
+			      as_bad (_("%s cannot use %s prefix"),
+				      insn->name, prefix_type);
+			      s++;
+			      continue;
+			    }
+			}
+		      else
+			{
+			  as_bad (_("parse error (%s)"), ob - 1);
+			  return;
+			}
+
+		      if (num_args != regtype - '0')
+			{
+			  as_bad (_("%s prefix specification requires %d parameters - [%s]"),
+				  prefix_type, regtype - '0' + 1,
+				  prefix_out);
+			}
+		      else
+			{
+			  int i = 8 - ((3 - num_args) * 2);
+			  char dummy_d[] = " m,m,m,m";
+			  char dummy_st[] = " x,y,z,w";
+
+			  if (*args == 'd' || *args == 'm')
+			    {
+			      strcat (prefix_out, dummy_d + i);
+			      if (has_saturater)
+				{
+				  as_bad (_("%s is restricted to mask destination prefixes only"),
+					  insn->name);
+				}
+			    }
+			  else
+			    {
+			      strcat (prefix_out, dummy_st + i);
+			      if (has_operator)
+				{
+				  as_bad (_("%s is restricted to swizzle %s prefixes only"),
+					  insn->name, prefix_type);
+				}
+			      /* semantic check, w can't be specified for
+				 s, p, or t instructions same goes for
+				 z for p and s, and y for scalars */
+			      if ((has_y && num_args == 0)
+				  || (has_z && num_args < 2)
+				  || (has_w && num_args < 3))
+				{
+				  as_bad (_("%s swizzle operand is out of range in [%s]"),
+					  prefix_type, prefix_out);
+				}
+			    }
+			}
+		    }
+
+		  continue;
+		}
+		break;
+
+	      case 'q':		/* VFPU destination control register */
+	      case 'r':		/* VFPU source control register */
+		{
+		  if ((s[0] == '$') && ISDIGIT (s[1]))
+		    {
+		      s++;
+		      regno = 0;
+		      do
+			{
+			  regno *= 10;
+			  regno += *s - '0';
+			  ++s;
+			}
+		      while (ISDIGIT (*s));
+
+		      if ((regno < VF_MIN_CR) || (regno > VF_MAX_CR))
+			as_bad (_("Invalid VFPU control register number (%d)"),
+				 regno);
+
+		      else if (!((regno >= VF_MIN_VCR) && (regno <= VF_MAX_VCR)))
+			as_bad (_("Improper VFPU control register number (%d)"),
+				 regno);
+
+		      switch (*args)
+			{
+			case 'q':
+			  ip->insn_opcode |= (regno & VF_MASK_VCD) << VF_SH_VCD;
+			  break;
+			case 'r':
+			  ip->insn_opcode |= (regno & VF_MASK_VCS) << VF_SH_VCS;
+			  break;
+			}
+		    }
+		  else
+		    {
+		      as_bad (_("Invalid VFPU control register name (%s)"), s);
+		    }
+
+		  continue;
+		}
+		break;
+
+	      case 'f':		/* condition code */
+		{
+		  int cond = 0;
+		  if (ISDIGIT (s[0]))
+		    {
+		      my_getExpression (&imm_expr, s);
+		      check_absolute_expr (ip, &imm_expr);
+		      cond = imm_expr.X_add_number;
+		      if ((cond < VF_MIN_CC) || (cond > VF_MAX_CC))
+			as_bad (_("Invalid VFPU condition code (%d)"), cond);
+		      imm_expr.X_op = O_absent;
+		      s = expr_end;
+		    }
+		  else
+		    {
+		      static const char * const vfpu_cond_names[] = {
+			"FL", "EQ", "LT", "LE",
+			"TR", "NE", "GE", "GT",
+			"EZ", "EN", "EI", "ES",
+			"NZ", "NN", "NI", "NS" };
+		      for (cond = VF_MIN_CC; cond <= VF_MAX_CC; cond++)
+			{
+			  if (strncasecmp(vfpu_cond_names[cond], s, 2) == 0)
+			    break;
+			}
+		      if ((cond < VF_MIN_CC) || (cond > VF_MAX_CC))
+			as_bad (_("Invalid VFPU condition code (%s)"), s);
+
+		      s += 2;
+		    }
+
+		  args++;
+		  if ((cond == 0) || (cond == 4))
+		    {
+		    }
+		  else if (cond & 0x8)
+		    {
+		      if (*args - '0' < 1)
+			as_bad (_("Invalid VFPU condition oparetion"));
+		    }
+		  else
+		    {
+		      if (*args - '0' < 2)
+			as_bad (_("Invalid VFPU condition oparetion"));
+		    }
+
+		  ip->insn_opcode |= (cond & VF_MASK_CC) << VF_SH_CC;
+		  continue;
+		}
+		break;
+
+	      case 'a':		/* constant code */
+		{
+		  int cst = 0;
+		  if (ISDIGIT (s[0]))
+		    {
+		      my_getExpression (&imm_expr, s);
+		      check_absolute_expr (ip, &imm_expr);
+		      cst = imm_expr.X_add_number;
+		      if ((cst < VF_MIN_CONST) || (cst > VF_MAX_CONST))
+			{
+			  as_bad (_("Improper constant code (%d)"), cst);
+			  cst &= VF_MASK_CONST;
+			}
+		      imm_expr.X_op = O_absent;
+		      s = expr_end;
+		    }
+		  else
+		    {
+		      static const char * const vfpu_const_names[] = {
+			"", "VFPU_HUGE", "VFPU_SQRT2", "VFPU_SQRT1_2",
+			"VFPU_2_SQRTPI", "VFPU_2_PI", "VFPU_1_PI", "VFPU_PI_4",
+			"VFPU_PI_2", "VFPU_PI", "VFPU_E", "VFPU_LOG2E",
+			"VFPU_LOG10E", "VFPU_LN2", "VFPU_LN10", "VFPU_2PI",
+			"VFPU_PI_6", "VFPU_LOG10TWO", "VFPU_LOG2TEN",
+			"VFPU_SQRT3_2"};
+		      for (cst = VF_MIN_CONST; cst <= VF_MAX_CONST; cst++)
+			{
+			  if (strcasecmp(vfpu_const_names[cst], s) == 0)
+			    break;
+			}
+		      if ((cst < VF_MIN_CONST) || (cst > VF_MAX_CONST))
+			as_bad (_("Invalid constant code (%s)"), s);
+		      else
+			s += strlen(vfpu_const_names[cst]);
+		    }
+
+		  ip->insn_opcode |= cst << VF_SH_CONST;
+		}
+		continue;
+
+	      case 'b':		/* scale exponent */
+		my_getExpression (&imm_expr, s);
+		check_absolute_expr (ip, &imm_expr);
+		if ((unsigned long) imm_expr.X_add_number > VF_MAX_SCALE)
+		  {
+		    as_bad (_("Improper scale (%lu)"),
+			     (unsigned long) imm_expr.X_add_number);
+		    imm_expr.X_add_number &= VF_MASK_SCALE;
+		  }
+		ip->insn_opcode |= imm_expr.X_add_number << VF_SH_SCALE;
+		imm_expr.X_op = O_absent;
+		s = expr_end;
+		continue;
+
+	      case 'c':		/* branch condition code bit */
+		my_getExpression (&imm_expr, s);
+		check_absolute_expr (ip, &imm_expr);
+		if ((unsigned long) imm_expr.X_add_number > VF_MAX_BCOND)
+		  {
+		    as_bad (_("Improper condition bit (%lu)"),
+			     (unsigned long) imm_expr.X_add_number);
+		    imm_expr.X_add_number &= VF_MASK_BCOND;
+		  }
+		ip->insn_opcode |= imm_expr.X_add_number << VF_SH_BCOND;
+		imm_expr.X_op = O_absent;
+		s = expr_end;
+		continue;
+
+	      case 'e':		/* move condition code bit */
+		my_getExpression (&imm_expr, s);
+		check_absolute_expr (ip, &imm_expr);
+		if ((unsigned long) imm_expr.X_add_number > VF_MAX_MCOND)
+		  {
+		    as_bad (_("Improper condition bit (%lu)"),
+			     (unsigned long) imm_expr.X_add_number);
+		    imm_expr.X_add_number &= VF_MASK_MCOND;
+		  }
+		ip->insn_opcode |= imm_expr.X_add_number << VF_SH_MCOND;
+		imm_expr.X_op = O_absent;
+		s = expr_end;
+		continue;
+
+	      case 'i':		/* wrap exponent */
+		my_getExpression (&imm_expr, s);
+		check_absolute_expr (ip, &imm_expr);
+		if ((unsigned long) imm_expr.X_add_number > VF_MAX_WRAP)
+		  {
+		    as_bad (_("Improper wrap (%lu)"),
+			     (unsigned long) imm_expr.X_add_number);
+		    imm_expr.X_add_number &= VF_MASK_WRAP;
+		  }
+		ip->insn_opcode |= imm_expr.X_add_number << VF_SH_WRAP;
+		imm_expr.X_op = O_absent;
+		s = expr_end;
+		continue;
+
+	      case 'w':		/* rotation code */
+		if (s[0] == '[')
+		  {
+		    char *rot_str = s;
+		    int rot_idx = 0;
+		    int rot_neg = 0;
+		    int rot_sin = 3;
+		    int rot_cos = 3;
+		    int rot_err = 0;
+		    int rot_n;
+		    int rot_neg_n = 0;
+		    int rot_sin_n = 0;
+		    int rot_cos_n = 0;
+		    int rot_code;
+
+		    if ((ip->insn_opcode & VFPU_MASK_DTYPE) == VFPU_PAIR)
+		      rot_n = 2;
+		    else if ((ip->insn_opcode & VFPU_MASK_DTYPE) == VFPU_TRIPLE)
+		      rot_n = 3;
+		    else if ((ip->insn_opcode & VFPU_MASK_DTYPE) == VFPU_QUAD)
+		      rot_n = 4;
+		    else
+		      rot_n = 0;
+
+		    s++;
+		    while ((s[0] != ']') && (s[0] != '\0'))
+		      {
+			if (s[0] == '-')
+			  {
+			    if ((s[1] != 's') && (s[1] != 'S'))
+			      {
+				rot_err = 1;
+				break;
+			      }
+			    rot_neg = 1;
+			    rot_neg_n++;
+			    s++;
+			  }
+
+			if (s[0] == ',')
+			  rot_idx++;
+			else if ((s[0] == 'c') || (s[0] == 'C'))
+			  {
+			    rot_cos = rot_idx;
+			    rot_cos_n++;
+			  }
+			else if ((s[0] == 's') || (s[0] == 'S'))
+			  {
+			    rot_sin = rot_idx;
+			    rot_sin_n++;
+			  }
+			else if (ISSPACE(s[0]) || (s[0] == '0'))
+			  ;
+			else
+			  {
+			    rot_err = 1;
+			    break;
+			  }
+
+			s++;
+		      }
+
+		    if (s[0] == ']')
+		      rot_idx++;
+		    else
+		      rot_err = 1;
+		    s++;
+
+		    if ((rot_sin_n == 0) && (rot_cos_n == 0))
+		      {
+			if (rot_n == 2)
+			  rot_sin = 2;
+			else if ((rot_n == 4) || (rot_n == 3))
+			  rot_err = 1;
+		      }
+
+		    if (rot_cos_n > 1)
+		      rot_err = 1;
+
+		    if (rot_sin_n > 1)
+		      {
+			if (((rot_sin_n + rot_cos_n) != rot_n)
+			    || ((rot_n == 4) && (rot_cos_n == 0)))
+			  rot_err = 1;
+		      }
+
+		    if (rot_neg && (rot_neg_n != rot_sin_n))
+		      rot_err = 1;
+
+		    if (rot_sin_n > 1)
+		      rot_sin = rot_cos;
+
+		    if (rot_err || (rot_n != rot_idx))
+		      as_bad (_("Invalid rotation code (%s)"), rot_str);
+
+		    rot_code = ((rot_neg & VF_MASK_ROT_NEG) << VF_SH_ROT_NEG)
+			     | ((rot_cos & VF_MASK_ROT_COS) << VF_SH_ROT_COS)
+			     | ((rot_sin & VF_MASK_ROT_SIN) << VF_SH_ROT_SIN);
+		    ip->insn_opcode |= rot_code << VF_SH_ROT;
+		  }
+		else
+		  {
+		    my_getExpression (&imm_expr, s);
+		    check_absolute_expr (ip, &imm_expr);
+		    if ((unsigned long) imm_expr.X_add_number > VF_MAX_ROT)
+		      {
+			as_bad (_("Improper rotation code (%lu)"),
+				 (unsigned long) imm_expr.X_add_number);
+			imm_expr.X_add_number &= VF_MASK_ROT;
+		      }
+		    ip->insn_opcode |= imm_expr.X_add_number << VF_SH_ROT;
+		    imm_expr.X_op = O_absent;
+		    s = expr_end;
+		  }
+		continue;
+
+	      case 'u':		/* half float */
+		if ((s[0] == '0') && ((s[1] == 'x') || (s[1] == 'X')))
+		  {
+		    my_getExpression (&imm_expr, s);
+		    check_absolute_expr (ip, &imm_expr);
+		    if ((unsigned long) imm_expr.X_add_number > VF_MAX_HFLOAT)
+		      {
+			as_bad (_("Improper half floating point constant: (%lu)"),
+				(unsigned long) imm_expr.X_add_number);
+			imm_expr.X_add_number &= VF_MASK_HFLOAT;
+		      }
+		    ip->insn_opcode |= imm_expr.X_add_number << VF_SH_HFLOAT;
+		    imm_expr.X_op = O_absent;
+		    s = expr_end;
+		    continue;
+		  }
+		else
+		  {
+		    char *save_in;
+		    char *err;
+		    int len;
+		    unsigned int length;
+		    unsigned char temp[8];
+		    unsigned int f32, f16;
+		    int exponent32, exponent16;
+		    int fraction32, fraction16;
+		    int sign;
+		    char f16_str[8];
+
+		    save_in = input_line_pointer;
+		    input_line_pointer = s;
+		    err = md_atof ('f', (char *) temp, &len);
+		    length = len;
+		    s = input_line_pointer;
+		    input_line_pointer = save_in;
+		    if (err != NULL && *err != '\0')
+		      {
+			as_bad (_("Bad half floating point constant: %s"), err);
+			memset (temp, '\0', sizeof temp);
+			length = 4;
+		      }
+
+		    if (! target_big_endian)
+		      f32 = bfd_getl32 (temp);
+		    else
+		      f32 = bfd_getb32 (temp);
+
+		    sign = (f32 >> VF_SH_F32_SIGN) & VF_MASK_F32_SIGN;
+		    exponent32 = (f32 >> VF_SH_F32_EXP) & VF_MASK_F32_EXP;
+		    fraction32 = (f32 >> VF_SH_F32_FRA) & VF_MASK_F32_FRA;
+		    exponent16 = exponent32
+			       - VF_BIAS_F32_EXP + VF_BIAS_F16_EXP;
+
+		    if (exponent16 < VF_MIN_F16_EXP)
+		      {
+			if ((exponent32 == VF_MIN_F32_EXP)
+			    && (fraction32 == 0))
+			  { // zero
+			    exponent16 = VF_MIN_F16_EXP;
+			    fraction16 = 0;
+			  }
+			else
+			  { // underflow
+				  float* p;
+				  p = (float*) &f32;
+			    as_warn (_("Half floating point underflow: %g"),
+				     *p);
+			    exponent16 = VF_MIN_F16_EXP;
+			    fraction16 = 0;
+			  }
+		      }
+		    else if (exponent16 > VF_MAX_F16_EXP)
+		      {
+			if (exponent32 != VF_MAX_F32_EXP)
+			  { // overflow
+			    as_warn (_("Half floating point overflow: %g"),
+				     *(float *)&f32);
+			    exponent16 = VF_MAX_F16_EXP;
+			    fraction16 = 0;
+			  }
+			else
+			  {
+			    if (fraction32 == 0)
+			      { // infinity
+				exponent16 = VF_MAX_F16_EXP;
+				fraction16 = 0;
+			      }
+			    else
+			      { // NaN
+				exponent16 = VF_MAX_F16_EXP;
+				fraction16 = 1;
+			      }
+			  }
+		      }
+		    else
+		      {
+			fraction16 = (f32 >> (VF_SH_F32_EXP - VF_SH_F16_EXP))
+				   & VF_MASK_F16_FRA;
+		      }
+
+		    f16 = (sign << VF_SH_F16_SIGN)
+			| (exponent16 << VF_SH_F16_EXP)
+			| (fraction16 << VF_SH_F16_FRA);
+		    ip->insn_opcode |= (f16 & VF_MASK_HFLOAT) << VF_SH_HFLOAT;
+
+		    sprintf(f16_str, "0x%04x", f16);
+		    my_getExpression (&imm_expr, f16_str);
+
+		    continue;
+		  }
+		break;
+
+	      case 'z':	 	/* read/write access code */
+		{
+		  int rwb = 0;
+
+		  if (strncasecmp (s, "WT", 2) == 0)
+		    rwb = 0x0;
+		  else if (strncasecmp (s, "WB", 2) == 0)
+		    rwb = 0x1;
+		  else
+		    as_bad (_("Invalid memory access type (%s)"), s);
+
+		  s += 2;
+		  ip->insn_opcode |= (rwb & VF_MASK_RWB) << VF_SH_RWB;
+
+		  continue;
+		}
+
+	      case '0':		/* source or target prefix code (X) */
+	      case '1':		/* source or target prefix code (Y) */
+	      case '2':		/* source or target prefix code (Z) */
+	      case '3':		/* source or target prefix code (W) */
+		{
+		  int operand;
+		  int shift;
+
+		  int pfx_neg = 0;
+		  int pfx_cst = 0;
+		  int pfx_abs = 0;
+		  int pfx_swz = 0;
+		  int pfx_err = 0;
+		  int cst = 0;
+		  char *pfx_str = s;
+
+		  if (s[0] == '-')
+		    {	// sign code
+		      pfx_neg = 1;
+		      s++;
+		    }
+		  
+		  if (ISDIGIT (s[0]))
+		    {	// constant
+		      pfx_cst = 1;
+
+		      if (s[0] == '0')
+			cst = 0;
+		      else if (s[0] == '1')
+			{
+			  if (s[1] == '/')
+			    {
+			      s += 2;
+			      if (s[0] == '2')
+				cst = 3;
+			      else if (s[0] == '3')
+				cst = 5;
+			      else if (s[0] == '4')
+				cst = 6;
+			      else if (s[0] == '6')
+				cst = 7;
+			      else
+				pfx_err = 1;
+			    }
+			  else
+			    {
+			      cst = 1;
+			    }
+			}
+		      else if (s[0] == '2')
+			cst = 2;
+		      else if (s[0] == '3')
+			cst = 4;
+		      else
+			pfx_err = 1;
+
+		      pfx_abs = (cst >> 2) & 0x1;
+		      pfx_swz = (cst >> 0) & 0x3;
+		      s++;
+		    }
+		  else
+		    {  // variable
+		      
+		      if (s[0] == '|')
+			{ // abs
+			  pfx_abs = 1;
+			  s++;
+			}
+		      
+		      if ((s[0] == 'X') || (s[0] == 'x'))
+			{
+			  pfx_swz = 0;
+			  s++;
+			}
+		      else if ((s[0] == 'Y') || (s[0] == 'y'))
+			{
+			  pfx_swz = 1;
+			  s++;
+			}
+		      else if ((s[0] == 'Z') || (s[0] == 'z'))
+			{
+			  pfx_swz = 2;
+			  s++;
+			}
+		      else if ((s[0] == 'W') || (s[0] == 'w'))
+			{
+			  pfx_swz = 3;
+			  s++;
+			}
+		      else if ((s[0] == ',') || IS_SPACE_OR_NUL (s[0])
+			       || (s[0] == '|'))
+			{
+			  pfx_swz =  *args - '0';
+			}
+		      else
+			pfx_err = 1;
+
+		      if (pfx_err == 0)
+			{
+			  if (s[0] == '|')
+			    {
+			      s++;
+			      if (pfx_abs == 0)
+				pfx_err = 1;
+			    }
+			  else
+			    {
+			      if (pfx_abs == 1)
+				pfx_err = 1;
+			    }
+			}
+		    }
+
+		  if (! ((s[0] == ',') || IS_SPACE_OR_NUL (s[0])))
+		    pfx_err = 1;
+
+		  if (pfx_err)
+		    as_bad (_("Invalid prefix format (%s)"), pfx_str);
+
+		  shift = *args - '0';
+
+		  operand = (pfx_neg << (VF_SH_PFX_NEG + shift))
+			  | (pfx_cst << (VF_SH_PFX_CST + shift))
+			  | (pfx_abs << (VF_SH_PFX_ABS + shift))
+			  | (pfx_swz << (VF_SH_PFX_SWZ + shift * 2));
+
+		  ip->insn_opcode |= operand;
+		  continue;
+		}
+
+	      case '4':		/* destination prefix code (X) */
+	      case '5':		/* destination prefix code (Y) */
+	      case '6':		/* destination prefix code (Z) */
+	      case '7':		/* destination prefix code (W) */
+		{
+		  int operand;
+		  int shift;
+		  static const char order[] = "xyzwXYZW";
+
+		  int pfx_msk = 0;
+		  int pfx_sat = 0;
+		  char *pfx_str = s;
+
+		  if (s[0] == '[')
+		    s++;
+		  if (s[0] == '-')	/* -1:1, skip the minus symbol */
+		    s++;
+
+		  if ((s[0] == 'm') || (s[0] == 'M'))
+		    {
+		      pfx_msk = 1;
+		      s++;
+		    }
+		  else if (s[0] == '0')	/* 0:1 */
+		    {
+		      pfx_sat = 1;
+		      s++;
+		    }
+		  else if (s[0] == '1')	/* -1:1 or -1:+1 */
+		    {
+		      pfx_sat = 3;
+		      s++;
+		    }
+		  else if ((s[0] == order[(*args) - '4'])
+			   || (s[0] == order[(*args) - '4' + 4]))
+		    {
+		      pfx_sat = 0;
+		      s++;
+		    }
+
+		  if (s[0] == ':')	/* skip the :1 or :+1 part of the expression */
+		    {
+		      s++;
+		      if (s[0] == '+')
+			s++;
+		      if (s[0] == '1')
+			s++;
+		    }
+		  if (s[0] == ']')
+		    s++;
+
+		  if (! ((s[0] == ',') || IS_SPACE_OR_NUL (s[0])))
+		    as_bad (_("Invalid prefix format (%s)"), pfx_str);
+
+		  shift = *args - '4';
+		  operand = (pfx_msk << (VF_SH_PFX_MSK + shift))
+			  | (pfx_sat << (VF_SH_PFX_SAT + shift * 2));
+
+		  ip->insn_opcode |= operand;
+		  continue;
+		}
+	      }
+	      break;
+
+	    case 'b':		/* base register */
+	    case 'd':		/* destination register */
+	    case 's':		/* source register */
+	    case 't':		/* target register */
+	    case 'r':		/* both target and source */
+	    case 'v':		/* both dest and source */
+	    case 'w':		/* both dest and target */
+	    case 'E':		/* coprocessor target register */
+	    case 'G':		/* coprocessor destination register */
+	    case 'K':		/* 'rdhwr' destination register */
+	    case 'x':		/* ignore register name */
+	    case 'z':		/* must be zero register */
+	    case 'U':           /* destination register (clo/clz).  */
+	      s_reset = s;
+	      if (s[0] == '$')
+		{
+
+		  if (ISDIGIT (s[1]))
+		    {
+		      ++s;
 		      regno = 0;
 		      do
 			{
@@ -8273,30 +9967,27 @@
 		    goto notreg;
 		  else
 		    {
-		      if (s[1] == 'r' && s[2] == 'a')
+				const char regName[32][5] =
 			{
-			  s += 3;
-			  regno = RA;
-			}
-		      else if (s[1] == 'f' && s[2] == 'p')
+					"zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
+					"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", 
+					"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
+					"t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"
+				};
+				int i;
+
+				for(i = 0; i < 32; i++)
 			{
-			  s += 3;
-			  regno = FP;
-			}
-		      else if (s[1] == 's' && s[2] == 'p')
+					if(strncmp(&s[1], regName[i], strlen(regName[i])) == 0)
 			{
-			  s += 3;
-			  regno = SP;
+						break;
 			}
-		      else if (s[1] == 'g' && s[2] == 'p')
-			{
-			  s += 3;
-			  regno = GP;
 			}
-		      else if (s[1] == 'a' && s[2] == 't')
+
+				if(i < 32)
 			{
-			  s += 3;
-			  regno = AT;
+					s += strlen(regName[i]) + 1;
+					regno = i;
 			}
 		      else if (s[1] == 'k' && s[2] == 't' && s[3] == '0')
 			{
@@ -8485,6 +10176,7 @@
 
 		  if ((regno & 1) != 0
 		      && HAVE_32BIT_FPRS
+		      && ! CPU_IS_ALLEGREX (mips_opts.arch)
 		      && ! (strcmp (str, "mtc1") == 0
 			    || strcmp (str, "mfc1") == 0
 			    || strcmp (str, "lwc1") == 0
@@ -13743,6 +15435,8 @@
 
   /* MIPS II */
   { "r6000",          0,      ISA_MIPS2,      CPU_R6000 },
+  /* Sony PSP "Allegrex" CPU core */
+  { "allegrex",       0,      ISA_MIPS2,      CPU_ALLEGREX },
 
   /* MIPS III */
   { "r4000",          0,      ISA_MIPS3,      CPU_R4000 },
