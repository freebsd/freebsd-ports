--- ../rary/TLEX.c.orig	2007-11-11 18:06:18.000000000 +0900
+++ ../rary/TLEX.c	2007-11-11 18:10:29.000000000 +0900
@@ -23,6 +23,8 @@
 	980604	added atbitrary string "**", char "[]" and frex_*()
 //////////////////////////////////////////////////////////////////////#*/
 
+#include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #ifndef NULL
@@ -78,6 +80,9 @@
 #define NEXT(fsp,ch) \
 	( fsp->Nstat ? fsp->Nstat->nvec[ch] : fsp->nnexts ? next(fsp,ch) : 0 )
 
+static fa_stvec_alloc(FaStat *fsp);
+static fa_rexp(FaStat *ofsp, unsigned char *regexp, int class);
+
 static FaStat*
 next1(fsp,ch)
 	FaStat *fsp;
