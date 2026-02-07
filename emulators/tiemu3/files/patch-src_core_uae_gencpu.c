--- src/core/uae/gencpu.c.orig	2007-11-20 18:01:02 UTC
+++ src/core/uae/gencpu.c
@@ -12,7 +12,7 @@
  * MC68000 instructions, plus a prototype header file and a function pointer
  * array to look up the function for an opcode.
  * Error checking is bad, an illegal table68k file will cause the program to
- * call abort().
+ * call uae_abort().
  * The generated code is sometimes sub-optimal, an optimizing compiler should
  * take care of this.
  *
@@ -89,7 +89,7 @@ static void read_counts (void)
 	}
     }
     if (nr != nr_cpuop_funcs)
-	abort ();
+	uae_abort ();
 }
 
 static char endlabelstr[80];
@@ -144,7 +144,7 @@ static int bit_size (int size)
      case sz_byte: return 8;
      case sz_word: return 16;
      case sz_long: return 32;
-     default: abort ();
+     default: uae_abort ();
     }
     return 0;
 }
@@ -155,7 +155,7 @@ static const char *bit_mask (int size)
      case sz_byte: return "0xff";
      case sz_word: return "0xffff";
      case sz_long: return "0xffffffff";
-     default: abort ();
+     default: uae_abort ();
     }
     return 0;
 }
@@ -370,7 +370,7 @@ static void genamode (amodes mode, char *reg, wordsize
     switch (mode) {
     case Dreg:
 	if (movem)
-	    abort ();
+	    uae_abort ();
 	if (getv == 1)
 	    switch (size) {
 	    case sz_byte:
@@ -393,12 +393,12 @@ static void genamode (amodes mode, char *reg, wordsize
 		printf ("\tuae_s32 %s = m68k_dreg(regs, %s);\n", name, reg);
 		break;
 	    default:
-		abort ();
+		uae_abort ();
 	    }
 	return;
     case Areg:
 	if (movem)
-	    abort ();
+	    uae_abort ();
 	if (getv == 1)
 	    switch (size) {
 	    case sz_word:
@@ -408,7 +408,7 @@ static void genamode (amodes mode, char *reg, wordsize
 		printf ("\tuae_s32 %s = m68k_areg(regs, %s);\n", name, reg);
 		break;
 	    default:
-		abort ();
+		uae_abort ();
 	    }
 	return;
     case Aind:
@@ -433,7 +433,7 @@ static void genamode (amodes mode, char *reg, wordsize
 	    printf ("\tuaecptr %sa = m68k_areg(regs, %s) - %d;\n", name, reg, movem ? 0 : 4);
 	    break;
 	default:
-	    abort ();
+	    uae_abort ();
 	}
 	break;
     case Ad16:
@@ -482,7 +482,7 @@ static void genamode (amodes mode, char *reg, wordsize
 	break;
     case imm:
 	if (getv != 1)
-	    abort ();
+	    uae_abort ();
 	switch (size) {
 	case sz_byte:
 	    printf ("\tuae_s8 %s = %s;\n", name, gen_nextibyte (flags & GF_NOREFILL));
@@ -494,31 +494,31 @@ static void genamode (amodes mode, char *reg, wordsize
 	    gen_nextilong ("uae_s32", name, flags & GF_NOREFILL);
 	    break;
 	default:
-	    abort ();
+	    uae_abort ();
 	}
 	return;
     case imm0:
 	if (getv != 1)
-	    abort ();
+	    uae_abort ();
 	printf ("\tuae_s8 %s = %s;\n", name, gen_nextibyte (flags & GF_NOREFILL));
 	return;
     case imm1:
 	if (getv != 1)
-	    abort ();
+	    uae_abort ();
 	printf ("\tuae_s16 %s = %s;\n", name, gen_nextiword (flags & GF_NOREFILL));
 	return;
     case imm2:
 	if (getv != 1)
-	    abort ();
+	    uae_abort ();
 	gen_nextilong ("uae_s32", name, flags & GF_NOREFILL);
 	return;
     case immi:
 	if (getv != 1)
-	    abort ();
+	    uae_abort ();
 	printf ("\tuae_u32 %s = %s;\n", name, reg);
 	return;
     default:
-	abort ();
+	uae_abort ();
     }
 
     /* We get here for all non-reg non-immediate addressing modes to
@@ -544,14 +544,14 @@ static void genamode (amodes mode, char *reg, wordsize
 	case sz_byte: insn_n_cycles += 4; break;
 	case sz_word: insn_n_cycles += 4; break;
 	case sz_long: insn_n_cycles += 8; break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	start_brace ();
 	switch (size) {
 	case sz_byte: printf ("\tuae_s8 %s = get_byte(%sa);\n", name, name); break;
 	case sz_word: printf ("\tuae_s16 %s = get_word(%sa);\n", name, name); break;
 	case sz_long: printf ("\tuae_s32 %s = get_long(%sa);\n", name, name); break;
-	default: abort ();
+	default: uae_abort ();
 	}
     }
 
@@ -571,7 +571,7 @@ static void genamode (amodes mode, char *reg, wordsize
 		printf ("\tm68k_areg(regs, %s) += 4;\n", reg);
 		break;
 	    default:
-		abort ();
+		uae_abort ();
 	    }
 	    break;
 	case Apdi:
@@ -597,7 +597,7 @@ static void genastore (char *from, amodes mode, char *
 	    printf ("\tm68k_dreg(regs, %s) = (%s);\n", reg, from);
 	    break;
 	 default:
-	    abort ();
+	    uae_abort ();
 	}
 	break;
      case Areg:
@@ -609,7 +609,7 @@ static void genastore (char *from, amodes mode, char *
 	    printf ("\tm68k_areg(regs, %s) = (%s);\n", reg, from);
 	    break;
 	 default:
-	    abort ();
+	    uae_abort ();
 	}
 	break;
      case Aind:
@@ -631,17 +631,17 @@ static void genastore (char *from, amodes mode, char *
 	 case sz_word:
 	    insn_n_cycles += 4;
 	    if (cpu_level < 2 && (mode == PC16 || mode == PC8r))
-		abort ();
+		uae_abort ();
 	    printf ("\tput_word(%sa,%s);\n", to, from);
 	    break;
 	 case sz_long:
 	    insn_n_cycles += 8;
 	    if (cpu_level < 2 && (mode == PC16 || mode == PC8r))
-		abort ();
+		uae_abort ();
 	    printf ("\tput_long(%sa,%s);\n", to, from);
 	    break;
 	 default:
-	    abort ();
+	    uae_abort ();
 	}
 	break;
      case imm:
@@ -649,10 +649,10 @@ static void genastore (char *from, amodes mode, char *
      case imm1:
      case imm2:
      case immi:
-	abort ();
+	uae_abort ();
 	break;
      default:
-	abort ();
+	uae_abort ();
     }
 }
 
@@ -746,7 +746,7 @@ static void genflags_normal (flagtypes type, wordsizes
 	strcpy (usstr, "((uae_u32)(");
 	break;
      default:
-	abort ();
+	uae_abort ();
     }
     strcpy (unsstr, usstr);
 
@@ -969,7 +969,7 @@ static const char *cmask (wordsizes size)
      case sz_byte: return "0x80";
      case sz_word: return "0x8000";
      case sz_long: return "0x80000000";
-     default: abort ();
+     default: uae_abort ();
     }
 }
 
@@ -1391,7 +1391,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 dst = (uae_s32)(uae_s8)src;\n"); break;
 	case sz_word: printf ("\tuae_u16 dst = (uae_s16)(uae_s8)src;\n"); break;
 	case sz_long: printf ("\tuae_u32 dst = (uae_s32)(uae_s16)src;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	genflags (flag_logical,
 		  curi->size == sz_word ? sz_word : sz_long, "dst", "", "");
@@ -1823,7 +1823,7 @@ static void gen_opcode (unsigned long int opcode)
 	    printf ("\tlower=get_long(dsta); upper = get_long(dsta+4);\n");
 	    break;
 	default:
-	    abort ();
+	    uae_abort ();
 	}
 	printf ("\tSET_ZFLG (upper == reg || lower == reg);\n");
 	printf ("\tSET_CFLG (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);\n");
@@ -1840,7 +1840,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 sign = (%s & val) >> %d;\n", cmask (curi->size), bit_size (curi->size) - 1);
 	printf ("\tcnt &= 63;\n");
@@ -1874,7 +1874,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -1911,7 +1911,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -1941,7 +1941,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -1972,7 +1972,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -2000,7 +2000,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -2028,7 +2028,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -2059,7 +2059,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tcnt &= 63;\n");
 	printf ("\tCLEAR_CZNV;\n");
@@ -2092,7 +2092,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 sign = %s & val;\n", cmask (curi->size));
 	printf ("\tuae_u32 cflg = val & 1;\n");
@@ -2110,7 +2110,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 sign = %s & val;\n", cmask (curi->size));
 	printf ("\tuae_u32 sign2;\n");
@@ -2131,7 +2131,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u32 val = (uae_u8)data;\n"); break;
 	case sz_word: printf ("\tuae_u32 val = (uae_u16)data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & 1;\n");
 	printf ("\tval >>= 1;\n");
@@ -2148,7 +2148,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u8 val = data;\n"); break;
 	case sz_word: printf ("\tuae_u16 val = data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & %s;\n", cmask (curi->size));
 	printf ("\tval <<= 1;\n");
@@ -2165,7 +2165,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u8 val = data;\n"); break;
 	case sz_word: printf ("\tuae_u16 val = data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & %s;\n", cmask (curi->size));
 	printf ("\tval <<= 1;\n");
@@ -2182,7 +2182,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u8 val = data;\n"); break;
 	case sz_word: printf ("\tuae_u16 val = data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & 1;\n");
 	printf ("\tval >>= 1;\n");
@@ -2199,7 +2199,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u8 val = data;\n"); break;
 	case sz_word: printf ("\tuae_u16 val = data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & %s;\n", cmask (curi->size));
 	printf ("\tval <<= 1;\n");
@@ -2217,7 +2217,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tuae_u8 val = data;\n"); break;
 	case sz_word: printf ("\tuae_u16 val = data;\n"); break;
 	case sz_long: printf ("\tuae_u32 val = data;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\tuae_u32 carry = val & 1;\n");
 	printf ("\tval >>= 1;\n");
@@ -2319,7 +2319,7 @@ static void gen_opcode (unsigned long int opcode)
 	case sz_byte: printf ("\tm68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;\n"); break;
 	case sz_word: printf ("\tm68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;\n"); break;
 	case sz_long: printf ("\tm68k_areg(regs, (extra >> 12) & 7) = src;\n"); break;
-	default: abort ();
+	default: uae_abort ();
 	}
 	printf ("\t} else {\n");
 	genastore ("src", Dreg, "(extra >> 12) & 7", curi->size, "");
@@ -2566,7 +2566,7 @@ static void gen_opcode (unsigned long int opcode)
 	printf ("\tmmu_op(opcode,extra);\n");
 	break;
     default:
-	abort ();
+	uae_abort ();
 	break;
     }
     finish_braces ();
@@ -2631,7 +2631,7 @@ static void generate_one_opcode (int rp)
     case 4: smsk = 7; break;
     case 5: smsk = 63; break;
     case 7: smsk = 3; break;
-    default: abort ();
+    default: uae_abort ();
     }
     dmsk = 7;
 
@@ -2680,7 +2680,7 @@ static void generate_one_opcode (int rp)
 #if 0
 	    /* Check that we can do the little endian optimization safely.  */
 	    if (pos < 8 && (dmsk >> (8 - pos)) != 0)
-		abort ();
+		uae_abort ();
 #endif	    
 	    if (pos)
 		printf ("\tuae_u32 dstreg = (opcode >> %d) & %d;\n",
