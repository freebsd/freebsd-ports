--- lib/coding.c.orig	Sat May  3 01:39:46 2003
+++ lib/coding.c	Sat May  3 01:41:08 2003
@@ -43,10 +43,10 @@
 
 static u_int GB2312(u_char ch1, u_char ch2)
 {
-    if (ch1 > 0x29)
-	return(((ch1 - 0x27) * 94 + ch2 - 0x21) << 5);
+    if (ch1 < 0x80)
+	return(((ch1 - 0x81) * 191 + ch2 - 0x40) << 5);
     else
-	return(((ch1 - 0x21) * 94 + ch2 - 0x21) << 5);
+	return(((ch1 - 0x81) * 191 + 63 + ch2 - 0x80) << 5);
 }
 
 static u_int BIG5(u_char ch1, u_char ch2)
@@ -135,7 +135,7 @@
 };
 
 struct fontLoaderRegs fldDRegs[] = {
-    {  FldGB2312,      0},
+    {     GB2312,      0},
     {FldJISX0208, 0x7424},
     { FldKSC5601, 0x7D7E},
     {FldJISX0208, 0x7424},
