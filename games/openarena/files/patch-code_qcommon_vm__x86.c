--- code/qcommon/vm_x86.c.orig	2016-04-01 10:07:17 UTC
+++ code/qcommon/vm_x86.c
@@ -90,8 +90,11 @@ static	int		ftolPtr = (int)qftol0F7F;
 void AsmCall(void);
 static void (*const asmCallPtr)(void) = AsmCall;
 
-
+#ifdef __clang__
+	int		callMask = 0;
+#else
 static	int		callMask = 0;
+#endif
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
