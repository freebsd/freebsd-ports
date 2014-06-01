--- code/qcommon/vm_x86.c.orig	2014-03-23 14:53:59.000000000 +0100
+++ code/qcommon/vm_x86.c	2014-03-23 14:55:33.000000000 +0100
@@ -91,7 +91,11 @@
 static void (*const asmCallPtr)(void) = AsmCall;
 
 
+#ifdef __clang__
+	int		callMask = 0;
+#else
 static	int		callMask = 0;
+#endif
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
