--- onew.c.orig	2014-05-25 11:54:18.000000000 +0900
+++ onew.c	2014-05-25 11:54:37.000000000 +0900
@@ -492,7 +492,7 @@
 	fflush(stdout);
 }
 static int prev_modef;
-ONEW_DISP_ROMKANMODE(cmode,chelp,modef)
+void ONEW_DISP_ROMKANMODE(cmode,chelp,modef)
 	char *cmode,*chelp;
 {
 	if( modef == prev_modef )
