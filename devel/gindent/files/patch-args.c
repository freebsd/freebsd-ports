--- args.c.orig	Thu Nov 16 19:01:04 2000
+++ args.c	Fri Apr 20 01:32:52 2001
@@ -1,3 +1,5 @@
+#define BERKELEY_DEFAULTS 1
+
 /* Copyright (c) 1999, 2000 Carlo Wood.  All rights reserved.
    Copyright (c) 1994 Joseph Arceneaux.  All rights reserved.
    Copyright (c) 1992 Free Software Foundation, Inc.  All rights reserved.
@@ -92,6 +94,7 @@
 static int exp_hnl;
 static int exp_i;
 static int exp_ip;
+static int exp_knf;
 static int exp_kr;
 static int exp_l;
 static int exp_lc;
@@ -208,6 +211,30 @@
   int *p_explicit;
 };
 
+#define BSD_PRO_SETTINGS	{"orig", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-nbap\0-nbad\0-bbo\0-hnl\0-bc\0-br\0-brs\0-c33\0-cd33\0-cdb\0-ce\0\
+-ci4\0-cli0\0-cp33\0-di16\0-fc1\0-fca\0-i4\0-l75\0-lp\0-npcs\0-nprs\0-psl\0\
+-sc\0-sai\0-saf\0-saw\0-nsob\0-nss\0-ts8\0",\
+   &exp_orig}
+
+#define KNF_PRO_SETTINGS	{"knf", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-bad\0-bap\0-nbbb\0-nbc\0-bbo\0-br\0-brs\0-nbs\0-c33\0-cd33\0-cdb\0\
+-ce\0-ci4\0-cli0\0-cp33\0-ncs\0-d0\0-di0\0-ndj\0-nfc1\0-nfca\0-hnl\0-i8\0-ip8\0\
+-l79\0-nlp\0-npcs\0-nprs\0-psl\0-sai\0-saf\0-saw\0-sc\0-nsob\0-nss\0",\
+   &exp_knf}
+
+#define KR_PRO_SETTINGS		{"kr", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0\
+-ncdb\0-ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0-npcs\0\
+-nprs\0-npsl\0-sai\0-saf\0-saw\0-cs\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0",\
+   &exp_kr}
+
+#define GNU_PRO_SETTINGS	{"gnu", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-nbad\0-bap\0-bbo\0-hnl\0-nbc\0-bl\0-bls\0-ncdb\0-cs\0-nce\0-di2\0\
+-ndj\0-nfc1\0-i2\0-ip5\0-lp\0-pcs\0-nprs\0-psl\0-nsc\0-sai\0-saf\0-saw\0\
+-nsob\0-bli2\0-cp1\0-nfca\0",\
+   &exp_gnu}
+
 #ifdef BERKELEY_DEFAULTS
 /* Settings for original defaults */
 struct pro pro[] = {
@@ -230,39 +257,40 @@
 #endif
   {"pi", PRO_INT, -1, ONOFF_NA, &paren_indent, &exp_pi},
   {"pcs", PRO_BOOL, false, ON, &proc_calls_space, &exp_pcs},
+  BSD_PRO_SETTINGS,
   {"o", PRO_BOOL, false, ON, &expect_output_file, &expect_output_file},
   {"nv", PRO_BOOL, false, OFF, &verbose, &exp_v},
-  {"nut", PRO_BOOL, true, OFF, &use_tabs, &exp_ut},
-  {"nss", PRO_BOOL, false, OFF, &space_sp_semicolon, &exp_ss},
-  {"nsob", PRO_BOOL, false, OFF, &swallow_optional_blanklines, &exp_sob},
-  {"nsc", PRO_BOOL, true, OFF, &star_comment_cont, &exp_sc},
-  {"nsaw", PRO_BOOL, true, OFF, &space_after_while, &exp_saw},
-  {"nsai", PRO_BOOL, true, OFF, &space_after_if, &exp_sai},
-  {"nsaf", PRO_BOOL, true, OFF, &space_after_for, &exp_saf},
-  {"npsl", PRO_BOOL, true, OFF, &procnames_start_line, &exp_psl},
-  {"nprs", PRO_BOOL, false, OFF, &parentheses_space, &exp_prs},
+  {"nut", PRO_BOOL, false, OFF, &use_tabs, &exp_ut},
+  {"nss", PRO_BOOL, true, OFF, &space_sp_semicolon, &exp_ss},
+  {"nsob", PRO_BOOL, true, OFF, &swallow_optional_blanklines, &exp_sob},
+  {"nsc", PRO_BOOL, false, OFF, &star_comment_cont, &exp_sc},
+  {"nsaw", PRO_BOOL, false, OFF, &space_after_while, &exp_saw},
+  {"nsai", PRO_BOOL, false, OFF, &space_after_if, &exp_sai},
+  {"nsaf", PRO_BOOL, false, OFF, &space_after_for, &exp_saf},
+  {"npsl", PRO_BOOL, false, OFF, &procnames_start_line, &exp_psl},
+  {"nprs", PRO_BOOL, true, OFF, &parentheses_space, &exp_prs},
   {"npro", PRO_IGN, 0, ONOFF_NA, 0, &exp_pro},
 #ifdef PRESERVE_MTIME
   {"npmt", PRO_BOOL, false, OFF, &preserve_mtime, &exp_pmt},
 #endif
-  {"npcs", PRO_BOOL, false, OFF, &proc_calls_space, &exp_pcs},
+  {"npcs", PRO_BOOL, true, OFF, &proc_calls_space, &exp_pcs},
   {"nlps", PRO_BOOL, false, OFF, &leave_preproc_space, &exp_lps},
   {"nlp", PRO_BOOL, true, OFF, &lineup_to_parens, &exp_lp},
   {"nip", PRO_SETTINGS, 0, ONOFF_NA, (int *) "-ip0", &exp_nip},
-  {"nhnl", PRO_BOOL, true, OFF, &honour_newlines, &exp_hnl},
+  {"nhnl", PRO_BOOL, false, OFF, &honour_newlines, &exp_hnl},
   {"nfca", PRO_BOOL, true, OFF, &format_comments, &exp_fca},
   {"nfc1", PRO_BOOL, true, OFF, &format_col1_comments, &exp_fc1},
   {"neei", PRO_BOOL, false, OFF, &extra_expression_indent, &exp_eei},
-  {"ndj", PRO_BOOL, false, OFF, &ljust_decl, &exp_dj},
-  {"ncs", PRO_BOOL, true, OFF, &cast_space, &exp_cs},
-  {"nce", PRO_BOOL, true, OFF, &cuddle_else, &exp_ce},
+  {"ndj", PRO_BOOL, true, OFF, &ljust_decl, &exp_dj},
+  {"ncs", PRO_BOOL, false, OFF, &cast_space, &exp_cs},
+  {"nce", PRO_BOOL, false, OFF, &cuddle_else, &exp_ce},
   {"ncdw", PRO_BOOL, false, OFF, &cuddle_do_while, &exp_cdw},
-  {"ncdb", PRO_BOOL, true, OFF, &comment_delimiter_on_blankline, &exp_cdb},
+  {"ncdb", PRO_BOOL, false, OFF, &comment_delimiter_on_blankline, &exp_cdb},
   {"nbs", PRO_BOOL, false, OFF, &blank_after_sizeof, &exp_bs},
   {"nbfda", PRO_BOOL, false, OFF, &break_function_decl_args, &exp_bfda},
   {"nbc", PRO_BOOL, true, ON, &leave_comma, &exp_bc},
-  {"nbbo", PRO_BOOL, true, OFF, &break_before_boolean_operator, &exp_bbo},
-  {"nbbb", PRO_BOOL, false, OFF, &blanklines_before_blockcomments, &exp_bbb},
+  {"nbbo", PRO_BOOL, false, OFF, &break_before_boolean_operator, &exp_bbo},
+  {"nbbb", PRO_BOOL, true, OFF, &blanklines_before_blockcomments, &exp_bbb},
   {"nbap", PRO_BOOL, false, OFF, &blanklines_after_procs, &exp_bap},
   {"nbadp", PRO_BOOL, false, OFF,
    &blanklines_after_declarations_at_proctop, &exp_badp},
@@ -270,29 +298,25 @@
   {"nbacc", PRO_BOOL, false, OFF,
    &blanklines_around_conditional_compilation, &exp_bacc},
   {"lps", PRO_BOOL, false, ON, &leave_preproc_space, &exp_lps},
-  {"lp", PRO_BOOL, true, ON, &lineup_to_parens, &exp_lp},
+  {"lp", PRO_BOOL, false, ON, &lineup_to_parens, &exp_lp},
   {"lc", PRO_INT, DEFAULT_RIGHT_COMMENT_MARGIN,
    ONOFF_NA, &comment_max_col, &exp_lc},
   {"l", PRO_INT, DEFAULT_RIGHT_MARGIN, ONOFF_NA, &max_col, &exp_l},
-  {"kr", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0-ncdb\0\
--ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0-npcs\0-nprs\0-npsl\0\
--cs\0-sai\0-saw\0-saf\0-nsc\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0", &exp_kr},
-  {"ip", PRO_INT, 4, ONOFF_NA, &indent_parameters, &exp_ip},
-  {"i", PRO_INT, 4, ONOFF_NA, &ind_size, &exp_i},
+  KR_PRO_SETTINGS,
+/* This is now the default. */
+  KNF_PRO_SETTINGS,
+  {"ip", PRO_INT, 8, ONOFF_NA, &indent_parameters, &exp_ip},
+  {"i", PRO_INT, 8, ONOFF_NA, &ind_size, &exp_i},
   {"hnl", PRO_BOOL, true, ON, &honour_newlines, &exp_hnl},
   {"h", PRO_FUNCTION, 0, ONOFF_NA, (int *) usage, &exp_version},
-  {"gnu", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-bbo\0-hnl\0-nbc\0-bl\0-bls\0-ncdb\0-cs\0-nce\0\
--di2\0-ndj\0-nfc1\0-i2\0-ip5\0-lp\0-pcs\0-nprs\0-psl\0-nsc\0-sai\0-saf\0-saw\0-nsob\0\
--bli2\0-cp1\0-nfca\0", &exp_gnu},
-  {"fca", PRO_BOOL, true, ON, &format_comments, &exp_fca},
-  {"fc1", PRO_BOOL, true, ON, &format_col1_comments, &exp_fc1},
+  GNU_PRO_SETTINGS,
+  {"fca", PRO_BOOL, false, ON, &format_comments, &exp_fca},
+  {"fc1", PRO_BOOL, false, ON, &format_col1_comments, &exp_fc1},
   {"eei", PRO_BOOL, false, ON, &extra_expression_indent, &exp_eei},
   {"dj", PRO_BOOL, false, ON, &ljust_decl, &exp_dj},
-  {"di", PRO_INT, 16, ONOFF_NA, &decl_indent, &exp_di},
+  {"di", PRO_INT, 0, ONOFF_NA, &decl_indent, &exp_di},
   {"d", PRO_INT, 0, ONOFF_NA, &unindent_displace, &exp_d},
-  {"cs", PRO_BOOL, true, ON, &cast_space, &exp_cs},
+  {"cs", PRO_BOOL, false, ON, &cast_space, &exp_cs},
   {"cp", PRO_INT, 33, ONOFF_NA, &else_endif_col, &exp_cp},
   {"cli", PRO_INT, 0, ONOFF_NA, &case_indent, &exp_cli},
   {"ci", PRO_INT, 4, ONOFF_NA, &continuation_indent, &exp_ci},
@@ -311,12 +335,12 @@
   {"bli", PRO_INT, 0, ONOFF_NA, &brace_indent, &exp_bli},
   {"bl", PRO_BOOL, true, OFF, &btype_2, &exp_bl},
   {"bfda", PRO_BOOL, false, ON, &break_function_decl_args, &exp_bfda},
-  {"bc", PRO_BOOL, true, OFF, &leave_comma, &exp_bc},
+  {"bc", PRO_BOOL, false, OFF, &leave_comma, &exp_bc},
   {"bbb", PRO_BOOL, false, ON, &blanklines_before_blockcomments, &exp_bbb},
-  {"bap", PRO_BOOL, false, ON, &blanklines_after_procs, &exp_bap},
-  {"badp", PRO_BOOL, false, ON,
+  {"bap", PRO_BOOL, true, ON, &blanklines_after_procs, &exp_bap},
+  {"badp", PRO_BOOL, true, ON,
    &blanklines_after_declarations_at_proctop, &exp_badp},
-  {"bad", PRO_BOOL, false, ON, &blanklines_after_declarations, &exp_bad},
+  {"bad", PRO_BOOL, true, ON, &blanklines_after_declarations, &exp_bad},
   {"bacc", PRO_BOOL, false, ON,
    &blanklines_around_conditional_compilation, &exp_bacc},
   {"T", PRO_KEY, 0, ONOFF_NA, 0, &exp_T},
@@ -347,10 +371,7 @@
 #endif
   {"pi", PRO_INT, -1, ONOFF_NA, &paren_indent, &exp_pi},
   {"pcs", PRO_BOOL, true, ON, &proc_calls_space, &exp_pcs},
-  {"orig", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbap\0-nbad\0-bbo\0-hnl\0-bc\0-br\0-brs\0-c33\0-cd33\0-cdb\0\
--ce\0-ci4\0-cli0\0-cp33\0-di16\0-fc1\0-fca\0-i4\0-l75\0-lp\0-npcs\0-nprs\0\
--psl\0-sc\0-sai\0-saf\0-saw\0-nsob\0-nss\0-ts8\0", &exp_orig},
+  BSD_PRO_SETTINGS,
   {"o", PRO_BOOL, false, ON, &expect_output_file, &expect_output_file},
   {"nv", PRO_BOOL, false, OFF, &verbose, &exp_v},
   {"nut", PRO_BOOL, true, OFF, &use_tabs, &exp_ut},
@@ -395,19 +416,14 @@
   {"lc", PRO_INT, DEFAULT_RIGHT_COMMENT_MARGIN,
    ONOFF_NA, &comment_max_col, &exp_lc},
   {"l", PRO_INT, DEFAULT_RIGHT_MARGIN, ONOFF_NA, &max_col, &exp_l},
-  {"kr", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0\
--ncdb\0-ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0\
--npcs\0-nprs\0-npsl\0-sai\0-saf\0-saw\0-cs\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0", &exp_kr},
+  KR_PRO_SETTINGS,
+  KNF_PRO_SETTINGS,
   {"ip", PRO_INT, 5, ONOFF_NA, &indent_parameters, &exp_ip},
   {"i", PRO_INT, 2, ONOFF_NA, &ind_size, &exp_i},
   {"hnl", PRO_BOOL, true, ON, &honour_newlines, &exp_hnl},
   {"h", PRO_FUNCTION, 0, ONOFF_NA, (int *) usage, &exp_version},
 /* This is now the default. */
-  {"gnu", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-bbo\0-hnl\0-nbc\0-bl\0-bls\0-ncdb\0-cs\0\
--nce\0-di2\0-ndj\0-nfc1\0-i2\0-ip5\0-lp\0-pcs\0-nprs\0-psl\0\
--nsc\0-sai\0-saf\0-saw\0-nsob\0-bli2\0-cp1\0-nfca\0", &exp_gnu},
+  GNU_PRO_SETTINGS,
   {"fca", PRO_BOOL, false, ON, &format_comments, &exp_fca},
   {"fc1", PRO_BOOL, false, ON, &format_col1_comments, &exp_fc1},
   {"eei", PRO_BOOL, false, ON, &extra_expression_indent, &exp_eei},
@@ -558,6 +574,9 @@
   {"blank-lines-after-declarations", "bad"},
   {"blank-lines-after-commas", "bc"},
   {"blank-before-sizeof", "bs"},
+  {"berkeley-kernel-style", "knf"},
+  {"berkeley-kernel-normal-form", "knf"},
+  {"kernel-normal-form", "knf"},
   {"berkeley-style", "orig"},
   {"berkeley", "orig"},
   {"Bill-Shannon", "bs"},
