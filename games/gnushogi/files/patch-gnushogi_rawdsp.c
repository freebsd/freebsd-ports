--- gnushogi/rawdsp.c.orig	2021-02-05 15:24:17 UTC
+++ gnushogi/rawdsp.c
@@ -43,11 +43,6 @@
 #include "gnushogi.h"
 #include "rawdsp.h"
 
-unsigned short MV[MAXDEPTH];
-int MSCORE;
-
-int mycnt1, mycnt2;
-char *DRAW;
 extern char *InPtr;
 extern short pscore[];
 
