--- gcc/c-family/c-format.cc.orig	2024-05-07 06:51:37 UTC
+++ gcc/c-family/c-format.cc
@@ -499,6 +499,17 @@ static const format_length_info printf_length_specs[] 
   { NO_FMT, NO_FMT, 0 }
 };
 
+static const format_length_info freebsd_kprintf_length_specs[] =
+{
+  { "h", FMT_LEN_h, STD_C89, "hh", FMT_LEN_hh, STD_C99, 0 },
+  { "l", FMT_LEN_l, STD_C89, "ll", FMT_LEN_ll, STD_C9L, 0 },
+  { "q", FMT_LEN_ll, STD_EXT, NO_FMT, 0 },
+  { "z", FMT_LEN_z, STD_C99, NO_FMT, 0 },
+  { "t", FMT_LEN_t, STD_C99, NO_FMT, 0 },
+  { "j", FMT_LEN_j, STD_C99, NO_FMT, 0 },
+  { NO_FMT, NO_FMT, 0 }
+};
+
 /* Length specifiers valid for asm_fprintf.  */
 static const format_length_info asm_fprintf_length_specs[] =
 {
@@ -733,6 +744,41 @@ static const format_char_info print_char_table[] =
   { NULL,  0, STD_C89, NOLENGTHS, NULL, NULL, NULL }
 };
 
+static const format_char_info freebsd_ext_char_info =
+  { NULL,   1, STD_EXT, { T89_C,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "",       "cR",  NULL };
+
+static const format_char_info freebsd_kprintf_char_table[] =
+{
+  /* C89 conversion specifiers.  */
+  { "di",  0, STD_C89, { T89_I,   T99_SC,  T89_S,   T89_L,   T9L_LL,  TEX_LL,  T99_SST, T99_PD,  T99_IM,  BADLEN,  BADLEN,  BADLEN,   T23_I8,  T23_I16, T23_I32, T23_I64, T23_IF8, T23_IF16, T23_IF32, T23_IF64 }, "-wp0 +'I",  "i",  NULL },
+  { "oxX", 0, STD_C89, { T89_UI,  T99_UC,  T89_US,  T89_UL,  T9L_ULL, TEX_ULL, T99_ST,  T99_UPD, T99_UIM, BADLEN,  BADLEN,  BADLEN,   T23_U8,  T23_U16, T23_U32, T23_U64, T23_UF8, T23_UF16, T23_UF32, T23_UF64 }, "-wp0#",     "i",  NULL },
+  { "u",   0, STD_C89, { T89_UI,  T99_UC,  T89_US,  T89_UL,  T9L_ULL, TEX_ULL, T99_ST,  T99_UPD, T99_UIM, BADLEN,  BADLEN,  BADLEN,   T23_U8,  T23_U16, T23_U32, T23_U64, T23_UF8, T23_UF16, T23_UF32, T23_UF64 }, "-wp0'I",    "i",  NULL },
+  { "fgG", 0, STD_C89, { T89_D,   BADLEN,  BADLEN,  T99_D,   BADLEN,  T89_LD,  BADLEN,  BADLEN,  BADLEN,  T23_D32, T23_D64, T23_D128, BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp0 +#'I", "",   NULL },
+  { "eE",  0, STD_C89, { T89_D,   BADLEN,  BADLEN,  T99_D,   BADLEN,  T89_LD,  BADLEN,  BADLEN,  BADLEN,  T23_D32, T23_D64, T23_D128, BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp0 +#I",  "",   NULL },
+  { "c",   0, STD_C89, { T89_I,   BADLEN,  BADLEN,  T94_WI,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-w",        "",   NULL },
+  { "s",   1, STD_C89, { T89_C,   BADLEN,  BADLEN,  T94_W,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp",       "cR", NULL },
+  { "p",   1, STD_C89, { T89_V,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-w",        "c",  NULL },
+  /* C99 conversion specifiers.  */
+  { "F",   0, STD_C99, { T99_D,   BADLEN,  BADLEN,  T99_D,   BADLEN,  T99_LD,  BADLEN,  BADLEN,  BADLEN,  T23_D32, T23_D64, T23_D128, BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp0 +#'I", "",   NULL },
+  { "aA",  0, STD_C99, { T99_D,   BADLEN,  BADLEN,  T99_D,   BADLEN,  T99_LD,  BADLEN,  BADLEN,  BADLEN,  T23_D32, T23_D64, T23_D128, BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp0 +#",   "",   NULL },
+  /* X/Open conversion specifiers.  */
+  { "C",   0, STD_EXT, { TEX_WI,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-w",        "",   NULL },
+  { "S",   1, STD_EXT, { TEX_W,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp",       "R",  NULL },
+  /* FreeBSD kernel extensions (src/sys/kern/subr_prf.c).
+     The format %b is supported to decode error registers.
+     Its usage is:	printf("reg=%b\n", regval, "<base><arg>*");
+     which produces:	reg=3<BITTWO,BITONE>
+     The format %D provides a hexdump given a pointer and separator string:
+     ("%6D", ptr, ":")		-> XX:XX:XX:XX:XX:XX
+     ("%*D", len, ptr, " ")	-> XX XX XX XX ...
+   */
+  { "b",   0, STD_EXT, { T89_I,   T99_SC,  T89_S,   T89_L,   T9L_LL,  TEX_LL,  T99_SST, T99_PD,  T99_IM,  BADLEN,  BADLEN,  BADLEN,   T23_I8,  T23_I16, T23_I32, T23_I64, T23_IF8, T23_IF16, T23_IF32, T23_IF64 }, "-wp",       "i",  &freebsd_ext_char_info },
+  { "D",   1, STD_EXT, { T89_V,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,  BADLEN,   BADLEN,   BADLEN }, "-wp",       "cR", &freebsd_ext_char_info },
+  { "r",   0, STD_C89, { T89_UI,  T99_UC,  T89_US,  T89_UL,  T9L_ULL, TEX_ULL, T99_ST,  T99_UPD, T99_UIM, BADLEN,  BADLEN,  BADLEN,   T23_U8,  T23_U16, T23_U32, T23_U64, T23_UF8, T23_UF16, T23_UF32, T23_UF64 }, "-wp0# +'I", "i",  NULL },
+  { "y",   0, STD_EXT, { T89_I,   T99_SC,  T89_S,   T89_L,   T9L_LL,  TEX_LL,  T99_SST, T99_PD,  T99_IM,  BADLEN,  BADLEN,  BADLEN,   T23_I8,  T23_I16, T23_I32, T23_I64, T23_IF8, T23_IF16, T23_IF32, T23_IF64 }, "-wp0 +'I",  "i",  NULL },
+  { NULL,  0, STD_C89, NOLENGTHS, NULL, NULL, NULL }
+};
+
 static const format_char_info asm_fprintf_char_table[] =
 {
   /* C89 conversion specifiers.  */
@@ -1003,6 +1049,18 @@ static const format_kind_info format_types_orig[] =
     strfmon_flag_specs, strfmon_flag_pairs,
     FMT_FLAG_ARG_CONVERT, 'w', '#', 'p', 0, 'L', 0,
     NULL, NULL
+  },
+  { "printf0",  printf_length_specs,  print_char_table, " +#0-'I", NULL,
+    printf_flag_specs, printf_flag_pairs,
+    FMT_FLAG_ARG_CONVERT|FMT_FLAG_DOLLAR_MULTIPLE|FMT_FLAG_USE_DOLLAR|FMT_FLAG_EMPTY_PREC_OK,
+    'w', 0, 'p', 0, 'L', 0,
+    &integer_type_node, &integer_type_node
+  },
+  { "freebsd_kprintf",  freebsd_kprintf_length_specs,  freebsd_kprintf_char_table, " +#0-'", NULL,
+    printf_flag_specs, printf_flag_pairs,
+    FMT_FLAG_ARG_CONVERT|FMT_FLAG_DOLLAR_MULTIPLE|FMT_FLAG_USE_DOLLAR|FMT_FLAG_EMPTY_PREC_OK,
+    'w', 0, 'p', 0, 'L', 0,
+    &integer_type_node, &integer_type_node
   }
 };
 
