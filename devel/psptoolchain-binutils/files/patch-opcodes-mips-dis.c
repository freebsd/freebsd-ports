--- opcodes/mips-dis.c.orig	2005-03-03 11:49:50.000000000 +0000
+++ opcodes/mips-dis.c	2006-05-09 02:55:36.000000000 +0100
@@ -140,6 +140,139 @@
   "c0_taglo",     "c0_taghi",     "c0_errorepc",  "c0_desave",
 };
 
+static const char * const vfpu_sreg_names[128] = {
+  "S000",  "S010",  "S020",  "S030",  "S100",  "S110",  "S120",  "S130",
+  "S200",  "S210",  "S220",  "S230",  "S300",  "S310",  "S320",  "S330",
+  "S400",  "S410",  "S420",  "S430",  "S500",  "S510",  "S520",  "S530",
+  "S600",  "S610",  "S620",  "S630",  "S700",  "S710",  "S720",  "S730",
+  "S001",  "S011",  "S021",  "S031",  "S101",  "S111",  "S121",  "S131",
+  "S201",  "S211",  "S221",  "S231",  "S301",  "S311",  "S321",  "S331",
+  "S401",  "S411",  "S421",  "S431",  "S501",  "S511",  "S521",  "S531",
+  "S601",  "S611",  "S621",  "S631",  "S701",  "S711",  "S721",  "S731",
+  "S002",  "S012",  "S022",  "S032",  "S102",  "S112",  "S122",  "S132",
+  "S202",  "S212",  "S222",  "S232",  "S302",  "S312",  "S322",  "S332",
+  "S402",  "S412",  "S422",  "S432",  "S502",  "S512",  "S522",  "S532",
+  "S602",  "S612",  "S622",  "S632",  "S702",  "S712",  "S722",  "S732",
+  "S003",  "S013",  "S023",  "S033",  "S103",  "S113",  "S123",  "S133",
+  "S203",  "S213",  "S223",  "S233",  "S303",  "S313",  "S323",  "S333",
+  "S403",  "S413",  "S423",  "S433",  "S503",  "S513",  "S523",  "S533",
+  "S603",  "S613",  "S623",  "S633",  "S703",  "S713",  "S723",  "S733"
+};
+
+static const char * const vfpu_vpreg_names[128] = {
+  "C000",  "C010",  "C020",  "C030",  "C100",  "C110",  "C120",  "C130",
+  "C200",  "C210",  "C220",  "C230",  "C300",  "C310",  "C320",  "C330",
+  "C400",  "C410",  "C420",  "C430",  "C500",  "C510",  "C520",  "C530",
+  "C600",  "C610",  "C620",  "C630",  "C700",  "C710",  "C720",  "C730",
+  "R000",  "R001",  "R002",  "R003",  "R100",  "R101",  "R102",  "R103",
+  "R200",  "R201",  "R202",  "R203",  "R300",  "R301",  "R302",  "R303",
+  "R400",  "R401",  "R402",  "R403",  "R500",  "R501",  "R502",  "R503",
+  "R600",  "R601",  "R602",  "R603",  "R700",  "R701",  "R702",  "R703",
+  "C002",  "C012",  "C022",  "C032",  "C102",  "C112",  "C122",  "C132",
+  "C202",  "C212",  "C222",  "C232",  "C302",  "C312",  "C322",  "C332",
+  "C402",  "C412",  "C422",  "C432",  "C502",  "C512",  "C522",  "C532",
+  "C602",  "C612",  "C622",  "C632",  "C702",  "C712",  "C722",  "C732",
+  "R020",  "R021",  "R022",  "R023",  "R120",  "R121",  "R122",  "R123",
+  "R220",  "R221",  "R222",  "R223",  "R320",  "R321",  "R322",  "R323",
+  "R420",  "R421",  "R422",  "R423",  "R520",  "R521",  "R522",  "R523",
+  "R620",  "R621",  "R622",  "R623",  "R720",  "R721",  "R722",  "R723"
+};
+
+static const char * const vfpu_vtreg_names[128] = {
+  "C000",  "C010",  "C020",  "C030",  "C100",  "C110",  "C120",  "C130",
+  "C200",  "C210",  "C220",  "C230",  "C300",  "C310",  "C320",  "C330",
+  "C400",  "C410",  "C420",  "C430",  "C500",  "C510",  "C520",  "C530",
+  "C600",  "C610",  "C620",  "C630",  "C700",  "C710",  "C720",  "C730",
+  "R000",  "R001",  "R002",  "R003",  "R100",  "R101",  "R102",  "R103",
+  "R200",  "R201",  "R202",  "R203",  "R300",  "R301",  "R302",  "R303",
+  "R400",  "R401",  "R402",  "R403",  "R500",  "R501",  "R502",  "R503",
+  "R600",  "R601",  "R602",  "R603",  "R700",  "R701",  "R702",  "R703",
+  "C001",  "C011",  "C021",  "C031",  "C101",  "C111",  "C121",  "C131",
+  "C201",  "C211",  "C221",  "C231",  "C301",  "C311",  "C321",  "C331",
+  "C401",  "C411",  "C421",  "C431",  "C501",  "C511",  "C521",  "C531",
+  "C601",  "C611",  "C621",  "C631",  "C701",  "C711",  "C721",  "C731",
+  "R010",  "R011",  "R012",  "R013",  "R110",  "R111",  "R112",  "R113",
+  "R210",  "R211",  "R212",  "R213",  "R310",  "R311",  "R312",  "R313",
+  "R410",  "R411",  "R412",  "R413",  "R510",  "R511",  "R512",  "R513",
+  "R610",  "R611",  "R612",  "R613",  "R710",  "R711",  "R712",  "R713"
+};
+
+static const char * const vfpu_vqreg_names[128] = {
+  "C000",  "C010",  "C020",  "C030",  "C100",  "C110",  "C120",  "C130",
+  "C200",  "C210",  "C220",  "C230",  "C300",  "C310",  "C320",  "C330",
+  "C400",  "C410",  "C420",  "C430",  "C500",  "C510",  "C520",  "C530",
+  "C600",  "C610",  "C620",  "C630",  "C700",  "C710",  "C720",  "C730",
+  "R000",  "R001",  "R002",  "R003",  "R100",  "R101",  "R102",  "R103",
+  "R200",  "R201",  "R202",  "R203",  "R300",  "R301",  "R302",  "R303",
+  "R400",  "R401",  "R402",  "R403",  "R500",  "R501",  "R502",  "R503",
+  "R600",  "R601",  "R602",  "R603",  "R700",  "R701",  "R702",  "R703",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  ""
+};
+
+static const char * const vfpu_mpreg_names[128] = {
+  "M000",  "",  "M020",  "",  "M100",  "",  "M120",  "",
+  "M200",  "",  "M220",  "",  "M300",  "",  "M320",  "",
+  "M400",  "",  "M420",  "",  "M500",  "",  "M520",  "",
+  "M600",  "",  "M620",  "",  "M700",  "",  "M720",  "",
+  "E000",  "",  "E002",  "",  "E100",  "",  "E102",  "",
+  "E200",  "",  "E202",  "",  "E300",  "",  "E302",  "",
+  "E400",  "",  "E402",  "",  "E500",  "",  "E502",  "",
+  "E600",  "",  "E602",  "",  "E700",  "",  "E702",  "",
+  "M002",  "",  "M022",  "",  "M102",  "",  "M122",  "",
+  "M202",  "",  "M222",  "",  "M302",  "",  "M322",  "",
+  "M402",  "",  "M422",  "",  "M502",  "",  "M522",  "",
+  "M602",  "",  "M622",  "",  "M702",  "",  "M722",  "",
+  "E020",  "",  "E022",  "",  "E120",  "",  "E122",  "",
+  "E220",  "",  "E222",  "",  "E320",  "",  "E322",  "",
+  "E420",  "",  "E422",  "",  "E520",  "",  "E522",  "",
+  "E620",  "",  "E622",  "",  "E720",  "",  "E722",  ""
+};
+
+static const char * const vfpu_mtreg_names[128] = {
+  "M000",  "M010",  "",  "",  "M100",  "M110",  "",  "",
+  "M200",  "M210",  "",  "",  "M300",  "M310",  "",  "",
+  "M400",  "M410",  "",  "",  "M500",  "M510",  "",  "",
+  "M600",  "M610",  "",  "",  "M700",  "M710",  "",  "",
+  "E000",  "E001",  "",  "",  "E100",  "E101",  "",  "",
+  "E200",  "E201",  "",  "",  "E300",  "E301",  "",  "",
+  "E400",  "E401",  "",  "",  "E500",  "E501",  "",  "",
+  "E600",  "E601",  "",  "",  "E700",  "E701",  "",  "",
+  "M001",  "M011",  "",  "",  "M101",  "M111",  "",  "",
+  "M201",  "M211",  "",  "",  "M301",  "M311",  "",  "",
+  "M401",  "M411",  "",  "",  "M501",  "M511",  "",  "",
+  "M601",  "M611",  "",  "",  "M701",  "M711",  "",  "",
+  "E010",  "E011",  "",  "",  "E110",  "E111",  "",  "",
+  "E210",  "E211",  "",  "",  "E310",  "E311",  "",  "",
+  "E410",  "E411",  "",  "",  "E510",  "E511",  "",  "",
+  "E610",  "E611",  "",  "",  "E710",  "E711",  "",  ""
+};
+
+static const char * const vfpu_mqreg_names[128] = {
+  "M000",  "",  "",  "",  "M100",  "",  "",  "",
+  "M200",  "",  "",  "",  "M300",  "",  "",  "",
+  "M400",  "",  "",  "",  "M500",  "",  "",  "",
+  "M600",  "",  "",  "",  "M700",  "",  "",  "",
+  "E000",  "",  "",  "",  "E100",  "",  "",  "",
+  "E200",  "",  "",  "",  "E300",  "",  "",  "",
+  "E400",  "",  "",  "",  "E500",  "",  "",  "",
+  "E600",  "",  "",  "",  "E700",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  "",
+  "",  "",  "",  "",  "",  "",  "",  ""
+};
+
 static const struct mips_cp0sel_name mips_cp0sel_names_mips3264[] = {
   { 16, 1, "c0_config1"		},
   { 16, 2, "c0_config2"		},
@@ -288,6 +421,54 @@
   "$24",  "$25",  "$26",  "$27",  "$28",  "$29",  "$30",  "$31"
 };
 
+static const char * const vfpu_cond_names[16] = {
+  "FL",  "EQ",  "LT",  "LE",  "TR",  "NE",  "GE",  "GT",
+  "EZ",  "EN",  "EI",  "ES",  "NZ",  "NN",  "NI",  "NS"
+};
+
+static const char * const vfpu_const_names[20] = {
+  "",
+  "VFPU_HUGE",
+  "VFPU_SQRT2",
+  "VFPU_SQRT1_2",
+  "VFPU_2_SQRTPI",
+  "VFPU_2_PI",
+  "VFPU_1_PI",
+  "VFPU_PI_4",
+  "VFPU_PI_2",
+  "VFPU_PI",
+  "VFPU_E",
+  "VFPU_LOG2E",
+  "VFPU_LOG10E",
+  "VFPU_LN2",
+  "VFPU_LN10",
+  "VFPU_2PI",
+  "VFPU_PI_6",
+  "VFPU_LOG10TWO",
+  "VFPU_LOG2TEN",
+  "VFPU_SQRT3_2"
+};
+
+#define VFPU_NUM_CONSTANTS \
+  ((sizeof vfpu_const_names) / (sizeof (vfpu_const_names[0])))
+const unsigned int vfpu_num_constants = VFPU_NUM_CONSTANTS;
+
+static const char * const vfpu_rwb_names[4] = {
+  "wt",  "wb",  "",  ""
+};
+
+static const char * const pfx_cst_names[8] = {
+  "0",  "1",  "2",  "1/2",  "3",  "1/3",  "1/4",  "1/6"
+};
+
+static const char * const pfx_swz_names[4] = {
+  "x",  "y",  "z",  "w"
+};
+
+static const char * const pfx_sat_names[4] = {
+  "",  "[0:1]",  "",  "[-1:1]"
+};
+
 struct mips_abi_choice {
   const char *name;
   const char * const *gpr_names;
@@ -359,6 +540,8 @@
     mips_cp0_names_numeric, NULL, 0, mips_hwr_names_numeric },
   { "mips5",	1, bfd_mach_mips5, CPU_MIPS5, ISA_MIPS5,
     mips_cp0_names_numeric, NULL, 0, mips_hwr_names_numeric },
+  { "allegrex", 1, bfd_mach_mips_allegrex, CPU_ALLEGREX, ISA_MIPS2,
+    mips_cp0_names_numeric, NULL, 0, mips_hwr_names_numeric },
 
   /* For stock MIPS32, disassemble all applicable MIPS-specified ASEs.
      Note that MIPS-3D and MDMX are not applicable to MIPS32.  (See
@@ -1031,6 +1214,349 @@
 				 (l >> OP_SH_FT) & OP_MASK_FT);
 	  break;
 
+	case '?':
+	  /* VFPU extensions.  */
+	  d++;
+	  switch (*d)
+	    {
+	    case '\0':
+	      /* xgettext:c-format */
+	      (*info->fprintf_func) (info->stream,
+				     _("# internal error, incomplete VFPU extension sequence (?)"));
+	      return;
+
+	    case 'o':
+	      delta = (l >> OP_SH_VFPU_DELTA) & OP_MASK_VFPU_DELTA;
+	      if (delta & 0x8000)
+		delta |= ~0xffff;
+	      (*info->fprintf_func) (info->stream, "%d",
+				     delta);
+	      break;
+
+	    case '0':
+	    case '1':
+	    case '2':
+	    case '3':
+	      {
+		unsigned int pos = *d, base = '0';
+		unsigned int negation = (l >> (pos - (base - VFPU_SH_PFX_NEG))) & VFPU_MASK_PFX_NEG;
+		unsigned int constant = (l >> (pos - (base - VFPU_SH_PFX_CST))) & VFPU_MASK_PFX_CST;
+		unsigned int abs_consthi =
+		    (l >> (pos - (base - VFPU_SH_PFX_ABS_CSTHI))) & VFPU_MASK_PFX_ABS_CSTHI;
+		unsigned int swz_constlo = (l >> ((pos - base) * 2)) & VFPU_MASK_PFX_SWZ_CSTLO;
+
+		if (negation)
+		  (*info->fprintf_func) (info->stream, "-");
+		if (constant)
+		  {
+		    (*info->fprintf_func) (info->stream, "%s",
+                                           pfx_cst_names[(abs_consthi << 2) | swz_constlo]);
+		  }
+		else
+		  {
+		    if (abs_consthi)
+		      (*info->fprintf_func) (info->stream, "|%s|",
+					     pfx_swz_names[swz_constlo]);
+		    else
+		      (*info->fprintf_func) (info->stream, "%s",
+					     pfx_swz_names[swz_constlo]);
+		  }
+	      }
+	      break;
+
+	    case '4':
+	    case '5':
+	    case '6':
+	    case '7':
+	      {
+		unsigned int pos = *d, base = '4';
+		unsigned int mask = (l >> (pos - (base - VFPU_SH_PFX_MASK))) & VFPU_MASK_PFX_MASK;
+		unsigned int saturation = (l >> ((pos - base) * 2)) & VFPU_MASK_PFX_SAT;
+
+		if (mask)
+		  (*info->fprintf_func) (info->stream, "m");
+		else
+		  (*info->fprintf_func) (info->stream, "%s",
+                                         pfx_sat_names[saturation]);
+	      }
+	      break;
+
+	    case 'a':
+	      {
+		unsigned int c = (l >> OP_SH_VFPU_CONST) & OP_MASK_VFPU_CONST;
+		if (c < vfpu_num_constants)
+		  {
+		    (*info->fprintf_func) (info->stream, "%s",
+					   vfpu_const_names[c]);
+		  }
+		break;
+	      }
+
+	    case 'b':
+	      /* 5-bit immediate value.  */
+	      (*info->fprintf_func) (info->stream, "%d",
+				     (l >> OP_SH_VFPU_IMM5) & OP_MASK_VFPU_IMM5);
+	      break;
+
+	    case 'c':
+	      /* VFPU condition code.  */
+	      (*info->fprintf_func) (info->stream, "%d",
+				     (l >> OP_SH_VFPU_CC) & OP_MASK_VFPU_CC);
+	      break;
+
+	    case 'e':
+	      /* 3-bit immediate value.  */
+	      (*info->fprintf_func) (info->stream, "%d",
+				     (l >> OP_SH_VFPU_IMM3) & OP_MASK_VFPU_IMM3);
+	      break;
+
+	    case 'f':
+	      /* Conditional compare.  */
+	      (*info->fprintf_func) (info->stream, "%s",
+				     vfpu_cond_names[(l >> OP_SH_VFPU_COND) & OP_MASK_VFPU_COND]);
+	      /* Apparently this specifier is unused.  */
+	      d++;
+	      break;
+
+	    case 'i':
+	      /* 8-bit immediate value.  */
+	      (*info->fprintf_func) (info->stream, "0x%02x",
+				     (l >> OP_SH_VFPU_IMM8) & OP_MASK_VFPU_IMM8);
+	      break;
+
+	    case 'q':
+	      /* VFPU control register (vmtvc).  */
+	      (*info->fprintf_func) (info->stream, "$%d",
+				     (l >> OP_SH_VFPU_VMTVC) & OP_MASK_VFPU_VMTVC);
+	      break;
+
+	    case 'r':
+	      /* VFPU control register (vmfvc).  */
+	      (*info->fprintf_func) (info->stream, "$%d",
+				     (l >> OP_SH_VFPU_VMFVC) & OP_MASK_VFPU_VMFVC);
+	      break;
+
+	    case 'u':
+	      /* Convert a VFPU 16-bit floating-point number to IEEE754. */
+	      {
+		union float2int {
+			unsigned int i;
+			float f;
+		} float2int;
+		unsigned short float16 = (l >> OP_SH_VFPU_FLOAT16) & OP_MASK_VFPU_FLOAT16;
+		unsigned int sign = (float16 >> VFPU_SH_FLOAT16_SIGN) & VFPU_MASK_FLOAT16_SIGN;
+		int exponent = (float16 >> VFPU_SH_FLOAT16_EXP) & VFPU_MASK_FLOAT16_EXP;
+		unsigned int fraction = float16 & VFPU_MASK_FLOAT16_FRAC;
+		char signchar = '+' + ((sign == 1) * 2);
+
+		if (exponent == VFPU_FLOAT16_EXP_MAX)
+		  {
+		    if (fraction == 0)
+		      (*info->fprintf_func) (info->stream, "%cInf", signchar);
+		    else
+		      (*info->fprintf_func) (info->stream, "%cNaN", signchar);
+		  }
+		else if (exponent == 0 && fraction == 0)
+		  {
+		    (*info->fprintf_func) (info->stream, "%c0", signchar);
+		  }
+		else
+		  {
+		    if (exponent == 0)
+		      {
+			do
+			  {
+			    fraction <<= 1;
+			    exponent--;
+			  }
+			while (!(fraction & (VFPU_MASK_FLOAT16_FRAC + 1)));
+
+			fraction &= VFPU_MASK_FLOAT16_FRAC;
+		      }
+
+		    /* Convert to 32-bit single-precision IEEE754. */
+		    float2int.i = sign << 31;
+		    float2int.i |= (exponent + 112) << 23;
+		    float2int.i |= fraction << 13;
+		    (*info->fprintf_func) (info->stream, "%g", float2int.f);
+		  }
+	      }
+	      break;
+
+	    case 'w':
+	      {
+		const char *elements[4];
+		unsigned int opcode = l & VFPU_MASK_OP_SIZE;
+		unsigned int rotators = (l >> OP_SH_VFPU_ROT) & OP_MASK_VFPU_ROT;
+		unsigned int opsize, rothi, rotlo, negation, i;
+
+		/* Determine the operand size so we'll know how many elements to output. */
+		if (opcode == VFPU_OP_SIZE_PAIR)
+		  opsize = 2;
+		else if (opcode == VFPU_OP_SIZE_TRIPLE)
+		  opsize = 3;
+		else
+		  opsize = (opcode == VFPU_OP_SIZE_QUAD) * 4;	/* Sanity check. */
+
+		rothi = (rotators >> VFPU_SH_ROT_HI) & VFPU_MASK_ROT_HI;
+		rotlo = (rotators >> VFPU_SH_ROT_LO) & VFPU_MASK_ROT_LO;
+		negation = (rotators >> VFPU_SH_ROT_NEG) & VFPU_MASK_ROT_NEG;
+
+		if (rothi == rotlo)
+		  {
+		    if (negation)
+		      {
+			elements[0] = "-s";
+			elements[1] = "-s";
+			elements[2] = "-s";
+			elements[3] = "-s";
+		      }
+		    else
+		      {
+			elements[0] = "s";
+			elements[1] = "s";
+			elements[2] = "s";
+			elements[3] = "s";
+		      }
+		  }
+		else
+		  {
+		    elements[0] = "0";
+		    elements[1] = "0";
+		    elements[2] = "0";
+		    elements[3] = "0";
+		  }
+		if (negation)
+		  elements[rothi] = "-s";
+		else
+		  elements[rothi] = "s";
+		elements[rotlo] = "c";
+
+		(*info->fprintf_func) (info->stream, "[");
+		i = 0;
+		for (;;)
+		  {
+		    (*info->fprintf_func) (info->stream, "%s",
+					   elements[i++]);
+		    if (i >= opsize)
+		      break;
+		    (*info->fprintf_func) (info->stream, ",");
+		  }
+		(*info->fprintf_func) (info->stream, "]");
+	      }
+	      break;
+
+	    case 'd':
+	    case 'm':
+	    case 'n':
+	    case 's':
+	    case 't':
+	    case 'v':
+	    case 'x':
+	      {
+		unsigned int vreg = 0;
+
+		/* The first char specifies the bitfield that contains the register number. */
+		switch (*d)
+		  {
+		  case 'd':
+		  case 'v':
+		  case 'x':
+		    vreg = (l >> OP_SH_VFPU_VD) & OP_MASK_VFPU_VD;
+		    break;
+
+		  case 'm':
+		    /* Combine bits 0-4 of vt with bits 5-6 of vt. */
+		    vreg = ((l >> OP_SH_VFPU_VT_LO) & OP_MASK_VFPU_VT_LO)
+			    | ((l & OP_MASK_VFPU_VT_HI2) << OP_SH_VFPU_VT_HI);
+		    break;
+
+		  case 'n':
+		    /* Combine bits 0-4 of vt with bit 5 of vt. */
+		    vreg = ((l >> OP_SH_VFPU_VT_LO) & OP_MASK_VFPU_VT_LO)
+			    | ((l & OP_MASK_VFPU_VT_HI1) << OP_SH_VFPU_VT_HI);
+		    break;
+
+		  case 's':
+		    {
+			unsigned int temp_vreg = l >> OP_SH_VFPU_VS;
+
+			vreg = temp_vreg & OP_MASK_VFPU_VS;
+			if ((l & VFPU_OP_VT_VS_VD) == VFPU_OPCODE_VMMUL)
+			  {
+			    /* vmmul instructions have the RXC bit (bit 13) inverted. */
+			    if (temp_vreg & 0x20)
+			      vreg = temp_vreg & 0x5f;
+			    else
+			      vreg |= 0x20;
+			  }
+		    }
+		    break;
+
+		  case 't':
+		    vreg = (l >> OP_SH_VFPU_VT) & OP_MASK_VFPU_VT;
+		    break;
+		  }
+
+		/* The next char is the register set vreg comes from. */
+		d++;
+		switch (*d)
+		  {
+		  case '0':
+		    (*info->fprintf_func) (info->stream, "%s.s",
+					   vfpu_sreg_names[vreg]);
+		    break;
+
+		  case '1':
+		    (*info->fprintf_func) (info->stream, "%s.p",
+					   vfpu_vpreg_names[vreg]);
+		    break;
+
+		  case '2':
+		    (*info->fprintf_func) (info->stream, "%s.t",
+					   vfpu_vtreg_names[vreg]);
+		    break;
+
+		  case '3':
+		    (*info->fprintf_func) (info->stream, "%s.q",
+					   vfpu_vqreg_names[vreg]);
+		    break;
+
+		  case '5':
+		    (*info->fprintf_func) (info->stream, "%s.p",
+					   vfpu_mpreg_names[vreg]);
+		    break;
+
+		  case '6':
+		    (*info->fprintf_func) (info->stream, "%s.t",
+					   vfpu_mtreg_names[vreg]);
+		    break;
+
+		  case '7':
+		    (*info->fprintf_func) (info->stream, "%s.q",
+					   vfpu_mqreg_names[vreg]);
+		    break;
+
+		  default:
+		    /* xgettext:c-format */
+		    (*info->fprintf_func) (info->stream,
+					   _("# internal error, undefined vreg modifier(%c)"),
+					   *d);
+		    break;
+		  }
+
+		/* The last char is unused for disassembly. */
+		d++;
+	      }
+	      break;
+
+	    case 'z':
+	      (*info->fprintf_func) (info->stream, "%s",
+				     vfpu_rwb_names[(l >> OP_SH_VFPU_RWB) & OP_MASK_VFPU_RWB]);
+	      break;
+	    }
+	  break;
+
 	default:
 	  /* xgettext:c-format */
 	  (*info->fprintf_func) (info->stream,
