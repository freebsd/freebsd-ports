--- args.c.orig	Thu Nov 16 19:01:04 2000
+++ args.c	Sat Dec 16 12:27:45 2000
@@ -1,3 +1,5 @@
+#define BERKELEY_DEFAULTS 1
+
 /* Copyright (c) 1999, 2000 Carlo Wood.  All rights reserved.
    Copyright (c) 1994 Joseph Arceneaux.  All rights reserved.
    Copyright (c) 1992 Free Software Foundation, Inc.  All rights reserved.
@@ -208,6 +210,30 @@
   int *p_explicit;
 };
 
+#define BSD_PRO_SETTINGS	{"orig", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-nbap\0-nbad\0-bbo\0-hnl\0-bc\0-br\0-brs\0-c33\0-cd33\0-cdb\0-ce\0\
+-ci4\0-cli0\0-cp33\0-di16\0-fc1\0-fca\0-i4\0-l75\0-lp\0-npcs\0-nprs\0-psl\0\
+-sc\0-sai\0-saf\0-saw\0-nsob\0-nss\0-ts8\0",\
+   &exp_orig}
+
+#define KNF_PRO_SETTINGS		{"knf", PRO_SETTINGS, 0, ONOFF_NA,\
+   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0\
+-ncdb\0-ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0-npcs\0\
+-nprs\0-npsl\0-sai\0-saf\0-saw\0-cs\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0",\
+   &exp_kr}
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
@@ -230,6 +256,7 @@
 #endif
   {"pi", PRO_INT, -1, ONOFF_NA, &paren_indent, &exp_pi},
   {"pcs", PRO_BOOL, false, ON, &proc_calls_space, &exp_pcs},
+  BSD_PRO_SETTINGS,
   {"o", PRO_BOOL, false, ON, &expect_output_file, &expect_output_file},
   {"nv", PRO_BOOL, false, OFF, &verbose, &exp_v},
   {"nut", PRO_BOOL, true, OFF, &use_tabs, &exp_ut},
@@ -274,18 +301,12 @@
   {"lc", PRO_INT, DEFAULT_RIGHT_COMMENT_MARGIN,
    ONOFF_NA, &comment_max_col, &exp_lc},
   {"l", PRO_INT, DEFAULT_RIGHT_MARGIN, ONOFF_NA, &max_col, &exp_l},
-  {"kr", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0-ncdb\0\
--ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0-npcs\0-nprs\0-npsl\0\
--cs\0-sai\0-saw\0-saf\0-nsc\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0", &exp_kr},
+  KR_PRO_SETTINGS,
   {"ip", PRO_INT, 4, ONOFF_NA, &indent_parameters, &exp_ip},
   {"i", PRO_INT, 4, ONOFF_NA, &ind_size, &exp_i},
   {"hnl", PRO_BOOL, true, ON, &honour_newlines, &exp_hnl},
   {"h", PRO_FUNCTION, 0, ONOFF_NA, (int *) usage, &exp_version},
-  {"gnu", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-bbo\0-hnl\0-nbc\0-bl\0-bls\0-ncdb\0-cs\0-nce\0\
--di2\0-ndj\0-nfc1\0-i2\0-ip5\0-lp\0-pcs\0-nprs\0-psl\0-nsc\0-sai\0-saf\0-saw\0-nsob\0\
--bli2\0-cp1\0-nfca\0", &exp_gnu},
+  GNU_PRO_SETTINGS,
   {"fca", PRO_BOOL, true, ON, &format_comments, &exp_fca},
   {"fc1", PRO_BOOL, true, ON, &format_col1_comments, &exp_fc1},
   {"eei", PRO_BOOL, false, ON, &extra_expression_indent, &exp_eei},
@@ -347,10 +368,7 @@
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
@@ -395,19 +413,13 @@
   {"lc", PRO_INT, DEFAULT_RIGHT_COMMENT_MARGIN,
    ONOFF_NA, &comment_max_col, &exp_lc},
   {"l", PRO_INT, DEFAULT_RIGHT_MARGIN, ONOFF_NA, &max_col, &exp_l},
-  {"kr", PRO_SETTINGS, 0, ONOFF_NA,
-   (int *) "-nbad\0-bap\0-nbc\0-bbo\0-hnl\0-br\0-brs\0-c33\0-cd33\0\
--ncdb\0-ce\0-ci4\0-cli0\0-d0\0-di1\0-nfc1\0-i4\0-ip0\0-l75\0-lp\0\
--npcs\0-nprs\0-npsl\0-sai\0-saf\0-saw\0-cs\0-nsc\0-nsob\0-nfca\0-cp33\0-nss\0", &exp_kr},
+  KR_PRO_SETTINGS,
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
@@ -558,6 +570,9 @@
   {"blank-lines-after-declarations", "bad"},
   {"blank-lines-after-commas", "bc"},
   {"blank-before-sizeof", "bs"},
+  {"berkeley-kernel-style", "knf"},
+  {"berkeley-kernel-normal-form", "knf"},
+  {"kernel-normal-form", "knf"},
   {"berkeley-style", "orig"},
   {"berkeley", "orig"},
   {"Bill-Shannon", "bs"},
