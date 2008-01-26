--- src/unicon-im/ImmModules/cce/cin2tab.c.orig	2008-01-25 14:10:07.000000000 -0800
+++ src/unicon-im/ImmModules/cce/cin2tab.c	2008-01-25 14:32:40.000000000 -0800
@@ -162,7 +162,7 @@
 int i,k;
 char fname[64], fname_cin[64], fname_tab[64];
 char fname_phr[64],fname_lx[64];
-char tt[128];
+unsigned char tt[128];
 unsigned char *cmd, *arg;
 hz_input_table InpTable;
 int TotalKeyNum;
