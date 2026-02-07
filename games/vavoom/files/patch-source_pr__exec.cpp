--- source/pr_exec.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/pr_exec.cpp
@@ -1112,7 +1112,7 @@ func_loop:
 			{
 				Sys_Error("Division by 0");
 			}
-			BINOP(i, /=);
+			BINOP_Q(i, /=);
 			PR_VM_BREAK;
 
 		PR_VM_CASE(OPC_Modulus)
