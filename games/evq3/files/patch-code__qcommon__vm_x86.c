--- code/qcommon/vm_x86.c.orig	2014-11-28 23:31:38.000000000 +0300
+++ code/qcommon/vm_x86.c	2014-11-28 23:32:14.000000000 +0300
@@ -93,7 +93,7 @@
 #endif
 
 
-static	int		callMask = 0;
+int		callMask = 0;
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
