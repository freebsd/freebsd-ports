--- code/qcommon/vm_x86.c.orig	2013-10-18 02:26:13.000000000 +0300
+++ code/qcommon/vm_x86.c	2013-10-18 02:26:30.000000000 +0300
@@ -84,7 +84,7 @@
 #endif // !_WIN32
 
 
-static	int		callMask = 0; // bk001213 - init
+static	int __attribute__((used))		callMask = 0; // bk001213 - init
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
