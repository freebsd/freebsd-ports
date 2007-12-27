--- ../rary/JIS.c.orig	2007-11-11 18:13:21.000000000 +0900
+++ ../rary/JIS.c	2007-11-11 18:21:18.000000000 +0900
@@ -18,7 +18,7 @@
 //////////////////////////////////////////////////////////////////////#*/
 #include "ystring.h"
 #include <ctype.h>
-char *malloc();
+#include <stdlib.h>
 #include <stdio.h>
 extern FILE *fopen_LIBPATH();
 extern char *getTMPDIR();
@@ -92,6 +92,9 @@
 	IS_EUC_HI(hi) && (IS_EUC_LOS(lo) || IS_EUC_LOX(lo)))
 
 
+static UTF8toLocal(int ch1, int ch2, int ch3, int charset, unsigned char *op, unsigned char *ox);
+static EUCtoUTF8(int euc, char *us, char *ux);
+
 IS_SJIS_CHAR(ch1,ch2,in_sjis)
 {
 	if( ch1 & 0x80 ){
@@ -1457,6 +1460,8 @@
 unsigned short	u_u2lmap[0x10000];
 	int	u_init;
 } UcsX;
+static loadUnicodeMappings(char *jumap, UcsX *ucx, unsigned short l2ucnt[], unsigned short u2lcnt[]);
+
 #define L2Umap	ucx->u_l2umap
 #define U2Lmap	ucx->u_u2lmap
 static UcsX **UcsXtab;
