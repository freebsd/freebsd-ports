--- source/pr_exec.cpp.orig	2010-06-04 23:20:21.000000000 +0200
+++ source/pr_exec.cpp	2017-06-04 10:26:40.272597000 +0200
@@ -1112,7 +1112,7 @@
 			{
 				Sys_Error("Division by 0");
 			}
-			BINOP(i, /=);
+			BINOP_Q(i, /=);
 			PR_VM_BREAK;
 
 		PR_VM_CASE(OPC_Modulus)
