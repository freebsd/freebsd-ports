--- code/qcommon/vm_x86.c.orig	2014-04-17 13:05:34.157088687 +0200
+++ code/qcommon/vm_x86.c	2014-04-17 12:58:45.706901862 +0200
@@ -84,7 +84,7 @@
 #endif // !_WIN32
 
 
-static	int		callMask = 0; // bk001213 - init
+	int		callMask = 0; // bk001213 - init
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
