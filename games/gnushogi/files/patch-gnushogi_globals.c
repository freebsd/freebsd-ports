--- gnushogi/globals.c.orig	2014-02-16 18:20:24 UTC
+++ gnushogi/globals.c
@@ -51,6 +51,10 @@ char ColorStr[2][10];
 
 long znodes;
 
+unsigned short MV[MAXDEPTH];
+int MSCORE;
+int mycnt1, mycnt2;
+
 
 
 #ifdef BINBOOK
