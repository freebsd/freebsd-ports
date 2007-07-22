--- cmz80/z80.c.orig	Mon Oct 29 20:07:24 2001
+++ cmz80/z80.c	Sun Jul 22 13:54:12 2007
@@ -633,7 +633,7 @@
 #endif
 }
 
-/* inline */ static BYTE Inc(BYTE bArg)
+/* inline */ BYTE Inc(BYTE bArg)
 {
 #ifdef ARITH_TABLES
 	bArg++;
@@ -646,7 +646,7 @@
 #endif
 }
 
-/* inline */ static BYTE Dec(BYTE bArg)
+/* inline */ BYTE Dec(BYTE bArg)
 {
 #ifdef ARITH_TABLES
 	m_regF = (m_regF & C_FLAG) | rgfDec[bArg--];
