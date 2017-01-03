--- PDP10/pdp10_ksio.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_ksio.c
@@ -401,7 +401,7 @@ uint32 pa = (uint32) ea;
 int32 i, n, val;
 DIB *dibp;
 
-for (i = 0; dibp = dib_tab[i]; i++ ) {
+for (i = 0; (dibp = dib_tab[i]); i++ ) {
     if ((pa >= dibp->ba) &&
        (pa < (dibp->ba + dibp->lnt))) {
         dibp->rd (&val, pa, READ);
@@ -418,7 +418,7 @@ uint32 pa = (uint32) ea;
 int32 i, n;
 DIB *dibp;
 
-for (i = 0; dibp = dib_tab[i]; i++ ) {
+for (i = 0; (dibp = dib_tab[i]); i++ ) {
     if ((pa >= dibp->ba) &&
        (pa < (dibp->ba + dibp->lnt))) {
         dibp->wr ((int32) val, pa, mode);
